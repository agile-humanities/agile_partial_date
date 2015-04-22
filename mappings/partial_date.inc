<?php

/**
 * Implements hook_feeds_processor_targets_alter().
 *
 * @see FeedsNodeProcessor::getMappingTargets().
 *
 * @todo Only provides "end date" target if field allows it.
 */
function _partial_date_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {
  $field_info = field_info_instances($entity_type, $bundle_name); // ROSIE: is list of instances for this bundle keyed by machine name.
  foreach ($field_info as $name => $instance) {
    $info = field_info_field($name); // this gets the actual field info that includes the type.
    if ($info['type'] == 'partial_date') {
      $targets[$name . ':txt_short'] = array(
        'name' => t($name . ': Short Text Description'),
        'description' => t('Description of what my custom node field does.'),
        'callback' => 'partial_date_feeds_set_target',
        // Specify both summary_callback and form_callback to add a per mapping
        // configuration form.
        //'summary_callback' => 'my_module_summary_callback',
        //'form_callback' => 'my_module_form_callback',
      );
      $targets[$name . ':txt_long'] = array(
        'name' => t($name . ': Long Text Description'),
        'description' => t('Description of what my custom node field does.'),
        'callback' => 'partial_date_feeds_set_target',
        // Specify both summary_callback and form_callback to add a per mapping
        // configuration form.
        //'summary_callback' => 'my_module_summary_callback',
        //'form_callback' => 'my_module_form_callback',
      );
      $targets[$name . ':check_approximate'] = array(
        'name' => t($name . ': Approximate (bool)'),
        'description' => t('Description of what my custom node field does.'),
        'callback' => 'partial_date_feeds_set_target',
        // Specify both summary_callback and form_callback to add a per mapping
        // configuration form.
        //'summary_callback' => 'my_module_summary_callback',
        //'form_callback' => 'my_module_form_callback',
      );
      $targets[$name . ':year:start'] = array(
        'name' => t($name . ': Year: Start'),
        'description' => t('Description of what my custom node field does.'),
        'callback' => 'partial_date_feeds_set_target',
        // Specify both summary_callback and form_callback to add a per mapping
        // configuration form.
        //'summary_callback' => 'my_module_summary_callback',
        //'form_callback' => 'my_module_form_callback',
      );
      $targets[$name . ':year:end'] = array(
        'name' => t($name . ': Year: End'),
        'description' => t('Description of what my custom node field does.'),
        'callback' => 'partial_date_feeds_set_target',
        // Specify both summary_callback and form_callback to add a per mapping
        // configuration form.
        //'summary_callback' => 'my_module_summary_callback',
        //'form_callback' => 'my_module_form_callback',
      );

      $targets[$name . ':year:start'] = array(
        'name' => t($name . ': Year: Start'),
        'description' => t('Description of what my custom node field does.'),
        'callback' => 'partial_date_feeds_set_target',
        // Specify both summary_callback and form_callback to add a per mapping
        // configuration form.
        //'summary_callback' => 'my_module_summary_callback',
        //'form_callback' => 'my_module_form_callback',
      );



    }
  }

  // Move this stuff up into the if partial-date.
  if ($entity_type == 'node') {

    $targets['pd_year_start'] = array(
      'name' => t('Partial-Date-Field-Name: Year: Start'),
      'description' => t('Description of what my custom node field does.'),
      'callback' => 'my_module_set_target',
      // Specify both summary_callback and form_callback to add a per mapping
      // configuration form.
      'summary_callback' => 'my_module_summary_callback',
      'form_callback' => 'my_module_form_callback',
    );
    $targets['pd_year_end'] = array(
      'name' => t('Partial-Date-Field-Name: Year: End'),
      'description' => t('Description of what my custom node field does.'),
      'callback' => 'my_module_set_target',
      // Specify both summary_callback and form_callback to add a per mapping
      // configuration form.
      'summary_callback' => 'my_module_summary_callback',
      'form_callback' => 'my_module_form_callback',
    );
    $targets['pd_month'] = array(
      'name' => t('Partial-Date-Field-Name: Month'),
      'description' => t('Description of what my custom node field does.'),
      'callback' => 'my_module_set_target',
      // Specify both summary_callback and form_callback to add a per mapping
      // configuration form.
      'summary_callback' => 'my_module_summary_callback',
      'form_callback' => 'my_module_form_callback',
    );
    $targets['pd_month_start'] = array(
      'name' => t('Partial-Date-Field-Name: Month: Start'),
      'description' => t('Description of what my custom node field does.'),
      'callback' => 'my_module_set_target',
      // Specify both summary_callback and form_callback to add a per mapping
      // configuration form.
      'summary_callback' => 'my_module_summary_callback',
      'form_callback' => 'my_module_form_callback',
    );
    $targets['pd_month_end'] = array(
      'name' => t('Partial-Date-Field-Name: Month: End'),
      'description' => t('Description of what my custom node field does.'),
      'callback' => 'my_module_set_target',
      // Specify both summary_callback and form_callback to add a per mapping
      // configuration form.
      'summary_callback' => 'my_module_summary_callback',
      'form_callback' => 'my_module_form_callback',
    );
    $targets['pd_day'] = array(
      'name' => t('Partial-Date-Field-Name: Day'),
      'description' => t('Description of what my custom node field does.'),
      'callback' => 'my_module_set_target',
      // Specify both summary_callback and form_callback to add a per mapping
      // configuration form.
      'summary_callback' => 'my_module_summary_callback',
      'form_callback' => 'my_module_form_callback',
    );
    $targets['pd_day_start'] = array(
      'name' => t('Partial-Date-Field-Name: Day: Start'),
      'description' => t('Description of what my custom node field does.'),
      'callback' => 'my_module_set_target',
      // Specify both summary_callback and form_callback to add a per mapping
      // configuration form.
      'summary_callback' => 'my_module_summary_callback',
      'form_callback' => 'my_module_form_callback',
    );
    $targets['pd_day_end'] = array(
      'name' => t('Partial-Date-Field-Name: Day: End'),
      'description' => t('Description of what my custom node field does.'),
      'callback' => 'my_module_set_target',
      // Specify both summary_callback and form_callback to add a per mapping
      // configuration form.
      'summary_callback' => 'my_module_summary_callback',
      'form_callback' => 'my_module_form_callback',
    );

    $targets['pd_hour'] = array(
      'name' => t('Partial-Date-Field-Name: Hour'),
      'description' => t('Description of what my custom node field does.'),
      'callback' => 'my_module_set_target',
      // Specify both summary_callback and form_callback to add a per mapping
      // configuration form.
      'summary_callback' => 'my_module_summary_callback',
      'form_callback' => 'my_module_form_callback',
    );
    $targets['pd_hour_start'] = array(
      'name' => t('Partial-Date-Field-Name: Hour: Start'),
      'description' => t('Description of what my custom node field does.'),
      'callback' => 'my_module_set_target',
      // Specify both summary_callback and form_callback to add a per mapping
      // configuration form.
      'summary_callback' => 'my_module_summary_callback',
      'form_callback' => 'my_module_form_callback',
    );
    $targets['pd_hour_end'] = array(
      'name' => t('Partial-Date-Field-Name: Hour: End'),
      'description' => t('Description of what my custom node field does.'),
      'callback' => 'my_module_set_target',
      // Specify both summary_callback and form_callback to add a per mapping
      // configuration form.
      'summary_callback' => 'my_module_summary_callback',
      'form_callback' => 'my_module_form_callback',
    );
    $targets['pd_minute'] = array(
      'name' => t('Partial-Date-Field-Name: Minute'),
      'description' => t('Description of what my custom node field does.'),
      'callback' => 'my_module_set_target',
      // Specify both summary_callback and form_callback to add a per mapping
      // configuration form.
      'summary_callback' => 'my_module_summary_callback',
      'form_callback' => 'my_module_form_callback',
    );
    $targets['pd_second'] = array(
      'name' => t('Partial-Date-Field-Name: Second'),
      'description' => t('Description of what my custom node field does.'),
      'callback' => 'my_module_set_target',
      // Specify both summary_callback and form_callback to add a per mapping
      // configuration form.
      'summary_callback' => 'my_module_summary_callback',
      'form_callback' => 'my_module_form_callback',
    );
    $targets['pd_timezone'] = array(
      'name' => t('Partial-Date-Field-Name: Timezone'),
      'description' => t('Description of what my custom node field does.'),
      'callback' => 'my_module_set_target',
      // Specify both summary_callback and form_callback to add a per mapping
      // configuration form.
      'summary_callback' => 'my_module_summary_callback',
      'form_callback' => 'my_module_form_callback',
    );
    $targets['pd_estimate_year'] = array(
      'name' => t('Partial-Date-Field-Name: Estimate Year'),
      'description' => t('Description of what my custom node field does.'),
      'callback' => 'my_module_set_target',
      // Specify both summary_callback and form_callback to add a per mapping
      // configuration form.
      'summary_callback' => 'my_module_summary_callback',
      'form_callback' => 'my_module_form_callback',
    );
    $targets['pd_estimate_month'] = array(
      'name' => t('Partial-Date-Field-Name: Estimate Month'),
      'description' => t('Description of what my custom node field does.'),
      'callback' => 'my_module_set_target',
      // Specify both summary_callback and form_callback to add a per mapping
      // configuration form.
      'summary_callback' => 'my_module_summary_callback',
      'form_callback' => 'my_module_form_callback',
    );
    $targets['pd_estimate_day'] = array(
      'name' => t('Partial-Date-Field-Name: Estimate Day'),
      'description' => t('Description of what my custom node field does.'),
      'callback' => 'my_module_set_target',
      // Specify both summary_callback and form_callback to add a per mapping
      // configuration form.
      'summary_callback' => 'my_module_summary_callback',
      'form_callback' => 'my_module_form_callback',
    );
    $targets['pd_hour_estimate'] = array(
      'name' => t('Partial-Date-Field-Name: Hour Estimate'),
      'description' => t('Description of what my custom node field does.'),
      'callback' => 'my_module_set_target',
      // Specify both summary_callback and form_callback to add a per mapping
      // configuration form.
      'summary_callback' => 'my_module_summary_callback',
      'form_callback' => 'my_module_form_callback',
    );
    $targets['pd_minute_estimate'] = array(
      'name' => t('Partial-Date-Field-Name: Minute Estimate'),
      'description' => t('Description of what my custom node field does.'),
      'callback' => 'my_module_set_target',
      // Specify both summary_callback and form_callback to add a per mapping
      // configuration form.
      'summary_callback' => 'my_module_summary_callback',
      'form_callback' => 'my_module_form_callback',
    );
    $targets['pd_second_estimate'] = array(
      'name' => t('Partial-Date-Field-Name: Second Estimate'),
      'description' => t('Description of what my custom node field does.'),
      'callback' => 'my_module_set_target',
      // Specify both summary_callback and form_callback to add a per mapping
      // configuration form.
      'summary_callback' => 'my_module_summary_callback',
      'form_callback' => 'my_module_form_callback',
    );
    $targets['pd_short_date_text'] = array(
      'name' => t('Partial-Date-Field-Name: Short Date Text'),
      'description' => t('Description of what my custom node field does.'),
      'callback' => 'my_module_set_target',
      // Specify both summary_callback and form_callback to add a per mapping
      // configuration form.
      'summary_callback' => 'my_module_summary_callback',
      'form_callback' => 'my_module_form_callback',
    );
    $targets['pd_long_date_text'] = array(
      'name' => t('Partial-Date-Field-Name: Long date Text'),
      'description' => t('Description of what my custom node field does.'),
      'callback' => 'my_module_set_target',
      // Specify both summary_callback and form_callback to add a per mapping
      // configuration form.
      'summary_callback' => 'my_module_summary_callback',
      'form_callback' => 'my_module_form_callback',
    );
    $targets['pd_approximate'] = array(
      'name' => t('Partial-Date-Field-Name: Approximate'),
      'description' => t('Description of what my custom node field does.'),
      'callback' => 'my_module_set_target',
      // Specify both summary_callback and form_callback to add a per mapping
      // configuration form.
      'summary_callback' => 'my_module_summary_callback',
      'form_callback' => 'my_module_form_callback',
    );
  }
}

/**
 * Implements hook_feeds_set_target().
 *
 * @param $entity
 *   The target node.
 * @param $target
 *   The name of field on the target node to map to.
 * @param $feed_element
 *   The value to be mapped. Should be either a (flexible) date string
 *   or a FeedsDateTimeElement object. -- or a string, or perhaps a label?
 *
 */
function partial_date_feeds_set_target($source, $entity, $target, $feed_element)
{
  list($field_name, $sub_field) = explode(':', $target, 2);
  if (!is_array($feed_element)) {
    $feed_element = array($feed_element);
  }
  $delta = 0;
  foreach ($feed_element as $f) {
    switch ($sub_field) {
      case 'check_approximate':
        // keep going
      case 'txt_short':
        // keep going
      case 'txt_long':
        $entity->{$field_name}[$entity->language][$delta][$sub_field] = $feed_element;

      default:
        list($pd_element, $qualifier) = explode(':', $sub_field, 2);
        switch($pd_element) {
          case 'year':
            if 
        }
        $entity->{$field_name}[$entity->language][$delta]['from']['year'] = '1992';

    }
  }
  return;

  if (!($feed_element instanceof FeedsDateTimeElement)) {
    // DONE THIS
    if (!is_array($feed_element)) {
      $feed_element = array($feed_element);
    }//

    $delta = 0;
    foreach ($feed_element as $f) {
      if (empty($f) || !is_numeric($f) && !date_create($f)) {
        $array_element = new FeedsDateTimeElement(NULL, NULL);
      } elseif ($sub_field == 'end') {
        $array_element = new FeedsDateTimeElement(NULL, $f);
      } else {
        $array_element = new FeedsDateTimeElement($f, NULL);
      }
      $array_element->buildDateField($entity, $field_name, $delta);
      $delta++;
    }
  }
}