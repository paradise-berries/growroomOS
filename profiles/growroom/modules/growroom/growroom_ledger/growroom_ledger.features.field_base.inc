<?php
/**
 * @file
 * growroom_ledger.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function growroom_ledger_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_growroom_customer'.
  $field_bases['field_growroom_customer'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_growroom_customer',
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

  // Exported field_base: 'field_growroom_invoice_number'.
  $field_bases['field_growroom_invoice_number'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_growroom_invoice_number',
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

  // Exported field_base: 'field_growroom_seller'.
  $field_bases['field_growroom_seller'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_growroom_seller',
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

  // Exported field_base: 'field_growroom_total_price'.
  $field_bases['field_growroom_total_price'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_growroom_total_price',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'fraction',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'fraction',
  );

  // Exported field_base: 'field_growroom_unit_price'.
  $field_bases['field_growroom_unit_price'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_growroom_unit_price',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'fraction',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'fraction',
  );

  return $field_bases;
}
