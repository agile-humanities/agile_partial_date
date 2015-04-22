<?php

/**
 * Implements hook_feeds_processor_targets_alter().
 *
 * @see FeedsNodeProcessor::getMappingTargets().
 *
 * @todo Only provides "end date" target if field allows it.
 */
function _partial_date_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name)
{
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

      // TODO: only show the ones that are configured for this field.
      $has_range = strpos($info['type'], '_range');
      $range_ends = $has_range ? array('from', 'to') : array('from');
      foreach ($range_ends as $range_end) {
        foreach (array('year', 'month', 'day', 'hour', 'minute', 'second', 'timezone') as $qualifier) {

          // Check if the field instance contains this subfield.
          if ($instance['widget']['settings']['granularity'][$range_end][$qualifier]) {
            $targets[$name . ':' . $range_end . ':' . $qualifier] = array(
              'name' => t($name . ": $range_end : $qualifier"),
              'description' => t('Partial date element.'),
              'callback' => 'partial_date_feeds_set_target',
            );
          }
          if ($qualifier != 'timezone') {
            if ($instance['widget']['settings']['estimates'][$range_end][$qualifier]) {
              $targets[$name . ':' . $range_end . ':' . $qualifier . '_estimate'] = array(
                'name' => t($name . ": $range_end : $qualifier Estimate"),
                'description' => t('Partial date element.'),
                'callback' => 'partial_date_feeds_set_target',
              );
            }
          }
        }
      }
    }
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
  list($field_name, $sub_field, $sub_element) = explode(':', $target, 3);
  if (!is_array($feed_element)) {
    $feed_element = array($feed_element);
  }
  $delta = 0;
  foreach ($feed_element as $f) {
    switch ($sub_field) {
      case 'check_approximate':
      case 'txt_short':
      case 'txt_long':
        $entity->{$field_name}[$entity->language][$delta][$sub_field] = $f;
        $a = 1;
        break;

      case 'from':
      case 'to':
        $entity->{$field_name}[$entity->language][$delta][$sub_field][$sub_element] = $f;
        break;
    }
  }
  return;
}