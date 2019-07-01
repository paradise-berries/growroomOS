<?php
/**
 * @file
 * growroom_season.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function growroom_season_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_growroom_season'.
  $field_bases['field_growroom_season'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_growroom_season',
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
          'vocabulary' => 'growroom_season',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
