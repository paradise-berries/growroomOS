<?php

/**
 * @file
 * Growroom group views data.
 */

/**
 * Implements hook_views_data_alter().
 */
function growroom_group_views_data_alter(&$data) {

  $data['growroom_asset']['membership'] = array(
    'title' => t('Group membership'),
    'help' => t('The group(s) that this asset is a member of.'),
    'relationship' => array(
      'title' => t('Group membership'),
      'help' => t('Relate the growroom asset to its latest group membership log.'),
      'handler' => 'growroom_group_handler_relationship_membership',
      'base' => 'field_collection_item',
      'base field' => 'item_id',
      'label' => t('Group membership'),
    ),
  );
}

/**
 * Implements hook_field_views_data_alter().
 */
function growroom_group_field_views_data_alter(&$result, $field, $module) {

  // Replace the filter handler for field_growroom_group fields so that we can
  // expose a select list of group options.
  $owner_field = 'field_growroom_group';
  if ($field['field_name'] == $owner_field) {
    if (!empty($result['field_data_' . $owner_field][$owner_field . '_target_id']['filter'])) {
      $filter = &$result['field_data_' . $owner_field][$owner_field . '_target_id']['filter'];
      $filter['handler'] = 'growroom_group_handler_filter_asset_group';
    }
  }
}
