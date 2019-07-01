<?php

/**
 * @file
 * Growroom movement views data.
 */

/**
 * Implements hook_views_data_alter().
 */
function growroom_movement_views_data_alter(&$data) {

  $data['growroom_asset']['latest_movement'] = array(
    'title' => t('Latest movement'),
    'help' => t('The latest movement for this growroom asset.'),
    'relationship' => array(
      'title' => t('Latest movement'),
      'help' => t('Relate the growroom asset to its latest movement.'),
      'handler' => 'growroom_movement_handler_relationship_location',
      'base' => 'field_collection_item',
      'base field' => 'item_id',
      'label' => t('Latest movement'),
    ),
  );
}
