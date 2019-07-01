<?php

/**
 * @file
 * Growroom inventory views integration.
 */

/**
 * Implements hook_views_data().
 */
function growroom_inventory_views_data() {

  // Describe the {fgrowroom_inventory_asset_type} table to Views.
  $data['growroom_inventory_asset_type']['table']['group'] = t('Inventory asset type');

  // Create an implicit relationship to the growroom_asset_type table, so that it's
  // possible to link inventory configuration to assets.
  $data['growroom_inventory_asset_type']['table']['join'] = array(
    'growroom_asset' => array(
      'left_field' => 'type',
      'field' => 'type',
    ),
  );

  // Inventory enabled.
  $data['growroom_inventory_asset_type']['enabled'] = array(
    'title' => t('Inventory enabled'),
    'help' => t('Whether or not inventory is enabled for the asset type.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Enabled'),
      'type' => 'yes-no',
      'use equal' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Inventory enabled.
  $data['growroom_inventory_asset_type']['individual'] = array(
    'title' => t('Asset is individual'),
    'help' => t('Whether or not to treat assets as individuals if inventory adjustments are not available.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Individual'),
      'type' => 'yes-no',
      'use equal' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_data_alter().
 */
function growroom_inventory_views_data_alter(&$data) {

  // Asset inventory.
  $data['growroom_asset']['inventory'] = array(
    'title' => t('Asset inventory value'),
    'help' => t('The current asset inventory value.'),
    'field' => array(
      'handler' => 'growroom_inventory_handler_field_asset_inventory_value',
      'click sortable' => TRUE,
    ),
  );

  // Add custom asset type filter that only includes types with inventory
  // enabled.
  $data['growroom_asset']['inventory_asset_type'] = array(
    'title' => t('Asset type (inventory)'),
    'help' => t('Asset type (provided by growroom_inventory module).'),
    'filter' => array(
      'title' => t('Asset type (inventory)'),
      'help' => t('The growroom asset type, including only asset types with inventory enabled.'),
      'handler' => 'growroom_inventory_handler_filter_asset_type',
      'base' => 'growroom_asset',
      'base field' => 'id',
      'label' => t('Asset type (inventory)'),
    ),
  );
}
