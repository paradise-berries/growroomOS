<?php

/**
 * @file
 * Definition of growroom_group_handler_filter_asset_group.
 */

/**
 * Provide an exposed filter that presents user options in a select list.
 *
 * @ingroup views_filter_handlers
 */
class growroom_group_handler_filter_asset_group extends growroom_fields_handler_filter_entity {

  var $entity_type = 'growroom_asset';

  /**
   * Define the list of asset IDs to include in the exposed filter.
   */
  function entity_ids() {

    // Select all non-archived groups.
    $query = db_select('growroom_asset', 'fa');
    $query->addField('fa', 'id');
    $query->condition('fa.type', 'group');
    $query->condition('fa.archived', NULL);
    $query->orderby('fa.name');

    // Execute the query.
    $result = $query->execute();

    // Create an array of IDs.
    $ids = array();
    foreach ($result as $row) {
      $ids[] = $row->id;
    }

    // Return the IDs.
    return $ids;
  }
}
