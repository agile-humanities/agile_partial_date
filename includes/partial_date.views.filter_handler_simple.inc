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
  
}