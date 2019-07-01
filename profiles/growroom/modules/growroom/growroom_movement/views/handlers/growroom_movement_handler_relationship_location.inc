<?php

/**
 * @file
 * Growroom log location relationship handler.
 */

/**
 * Growroom log movement location relationship handler.
 *
 * Create a relationship between a growroom_asset, and it's most recent log entity's
 * movement field collection, in order to determine its current location.
 *
 * @see growroom_log_handler_relationship_asset
 */
class growroom_movement_handler_relationship_location extends growroom_log_handler_relationship_asset {

  /**
   * {@inheritdoc}
   */
  protected function build_query($asset_id, $time, $done) {
    return growroom_movement_asset_movement_query($asset_id, $time, $done, TRUE, 'movement_id');
  }

}
