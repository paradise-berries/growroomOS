<?php
/**
 * @file
 * growroom_asset_offspring.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function growroom_asset_offspring_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_growroom_parent'.
  $field_bases['field_growroom_parent'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_growroom_parent',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(),
      ),
      'target_type' => 'growroom_asset',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
