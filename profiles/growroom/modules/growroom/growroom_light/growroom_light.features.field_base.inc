<?php
/**
 * @file
 * growroom_light.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function growroom_light_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_growroom_light_names'.
  $field_bases['field_growroom_light_names'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_growroom_light_names',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'growroom_light_names',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
