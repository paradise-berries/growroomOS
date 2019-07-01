<?php
/**
 * @file
 * growroom_light_test.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function growroom_light_test_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_growroom_light_lab'.
  $field_bases['field_growroom_light_lab'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_growroom_light_lab',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
