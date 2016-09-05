<?php

class partial_date_views_filter_handler_simple extends date_views_filter_handler_simple {

  function init(&$view, &$options) {
    views_handler_filter_date::init($view, $options);
    module_load_include('inc', 'date_api', 'date_api_sql');
    $this->date_handler = new date_sql_handler(DATE_UNIX);
    if (!empty($this->definition['field_name'])) {
      $field = field_info_field($this->definition['field_name']);
      if (!empty($field) && !empty($field['type'])) {
        $this->date_handler->date_type = $field['type'];
      }
      // $field['settings']['tz_handling'] does not need to be set; this
      // is why we are overwriting the parent's init().
      $this->date_handler->db_timezone = date_get_timezone_db('utc'); //FIXME hardcoded to UTC
      $this->date_handler->local_timezone = date_get_timezone('utc');
    }
    $this->form_submitted = FALSE;
    $this->date_handler->granularity = isset($options['granularity']) ? $options['granularity'] : 'day';
    $this->format = $this->date_handler->views_formats($this->options['granularity'], 'sql');

    // Identify the base table for this field.
    // It will be used to call for the right query field options.
    $this->base_table = $this->table;
  }

  /**
   * Add a new widget to do partial date math.
   */
  function widget_options() {
    $options = parent::widget_options();
    $options['partial_date_select'] = t('Partial Select');
    return $options;
  }

  function op_contains($field) {

    // Add the delta field to the view so we can later find the value that matched our query.
    list($table_name, $field_name) = explode('.', $field);
    if (!empty($this->options['add_delta']) && (substr($field_name, -6) == '_value' || substr($field_name, -7) == '_value2')) {
      $this->query->add_field($table_name, 'delta');
    }

    $value = $this->get_filter_value('value', $this->value['value']);
    $value_to = array();
    foreach ($value as $key => $val) {
      $value_to[$key . '_to'] = $val;
    }
    $comp_partial_date = partial_date_float(partial_date_field_populate_components($value));
    $comp_partial_date_to = partial_date_float(partial_date_field_populate_components($value_to, 0));

    $field_min = $field;
    $field_max = $field . '_to';
    $placeholder_min = $this->placeholder();
    $placeholder_max = $this->placeholder();
    $group = !empty($this->options['date_group']) ? $this->options['date_group'] : $this->options['group'];
    $this->query->add_where_expression($group, "$field_max >= $placeholder_min AND $field_min <= $placeholder_max", array($placeholder_min => $comp_partial_date, $placeholder_max => $comp_partial_date_to));
  }

  /**
   * Override element_validate functions.
   */
  function value_form(&$form, &$form_state) {
    parent::value_form($form, $form_state);
    // Allow a partial date filter to be parsed if it's not complete.
    if ($this->options['form_type'] == 'partial_date_select') {
      $form['value']['#element_validate'] = array('partial_date_views_select_validate');
    }
  }

}
