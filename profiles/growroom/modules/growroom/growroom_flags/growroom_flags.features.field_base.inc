<?php
/**
 * @file
 * growroom_flags.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function growroom_flags_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_growroom_flags'.
  $field_bases['field_growroom_flags'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_growroom_flags',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_function' => 'growroom_flags_field_allowed_values',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
