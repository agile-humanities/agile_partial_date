<?php

class partial_date_views_filter_handler_simple extends date_views_filter_handler_simple {
  
  function init(&$view, &$options) {
    parent::init($view, $options);
  }

  function op_contains($field) {

    /** Not sure what this part does or why we need it!! -RL */
    // Add the delta field to the view so we can later find the value that matched our query.
    list($table_name, $field_name) = explode('.', $field);
    if (!empty($this->options['add_delta']) && (substr($field_name, -6) == '_value' || substr($field_name, -7) == '_value2')) {
      $this->query->add_field($table_name, 'delta');
    }

    $value = $this->get_filter_value('value', $this->value['value']);
    $comp_date = new DateObject($value, date_default_timezone(), $this->format);
    $value = $comp_date->format('YmdHis');
    $value = floatval($value);
    //$all_fields = date_views_views_fetch_fields($table_name, 'filter');
    //$fields = date_views_fields($this->base_table, TRUE);
    //$fields = $fields['name'];
//    $field_min = $this->date_handler->sql_field($from, NULL, $comp_date);
//    $field_min = $this->date_handler->sql_format('YmdHis', $field_min);
//    $field_max = $this->date_handler->sql_field($to, NULL, $comp_date);
//    $field_max = $this->date_handler->sql_format('YmdHis', $field_max);
    $field_min = $field;
    $field_max = $field . '_to';
    $placeholder_min = $this->placeholder();
    $placeholder_max = $this->placeholder();
    $group = !empty($this->options['date_group']) ? $this->options['date_group'] : $this->options['group'];
    $this->query->add_where_expression($group, "$field_max >= $placeholder_min AND $field_min <= $placeholder_max", array($placeholder_min => $value, $placeholder_max => $value));
  }
  /**
   * Helper function to see if we need to swap in the default value.
   *
   * Views exposed filters treat everything as submitted, so if it's an empty value we have to
   * see if anything actually was submitted. If nothing has really been submitted, we need
   * to swap in our default value logic.
   */
  function get_filter_value($prefix, $input) {
    // All our date widgets provide datetime values but we use ISO in our SQL
    // for consistency between the way filters and arguments work (arguments
    // cannot contain spaces).

    // Alan: Possibly we need to change code here to point to another type of date-getter if the full date is not entered.
    if (empty($input)) {
      if (empty($this->options['exposed'])) {
        return str_replace(' ', 'T', $this->date_default_value($prefix));
      }
      elseif (isset($this->options['expose']['identifier']) && !isset($_GET[$this->options['expose']['identifier']])) {
        return str_replace(' ', 'T', $this->date_default_value($prefix));
      }
    }

    return str_replace(' ', 'T', $input);
  }

  /**
   * Add the selectors to the value form using the date handler.
   */
  function value_form(&$form, &$form_state) {
    // We use different values than the parent form, so we must
    // construct our own form element.
    $form['value'] = array();
    $form['value']['#tree'] = TRUE;

    // Below section copied from views_handler_filter_numeric.inc.
    $which = 'all';
    $source = '';
    if (!empty($form['operator'])) {
      $source = ($form['operator']['#type'] == 'radios') ? 'radio:options[operator]' : 'edit-options-operator';
    }

    $identifier = $this->options['expose']['identifier'];
    if (!empty($form_state['exposed'])) {

      if (empty($this->options['expose']['use_operator']) || empty($this->options['expose']['operator_id'])) {
        // exposed and locked.
        $which = in_array($this->operator, $this->operator_values(2)) ? 'minmax' : 'value';
      }
      else {
        $source = 'edit-' . drupal_html_id($this->options['expose']['operator_id']);
      }
    }

    if ($which == 'all' || $which == 'value') {
      $form['value'] += $this->date_parts_form($form_state, 'value', $source, $which, $this->operator_values(1), $identifier, 'default_date');
    }

    if ($which == 'all' || $which == 'minmax') {
      $form['value'] += $this->date_parts_form($form_state, 'min', $source, $which, $this->operator_values(2), $identifier, 'default_date');
      $form['value'] += $this->date_parts_form($form_state, 'max', $source, $which, $this->operator_values(2), $identifier, 'default_to_date');
    }

    // Allow a partial date filter to be parsed if it's not complete.
    if ($this->options['form_type'] == 'date_select') {
      $form['value']['#element_validate'] = array('partial_date_views_select_validate');
    }

  }

}