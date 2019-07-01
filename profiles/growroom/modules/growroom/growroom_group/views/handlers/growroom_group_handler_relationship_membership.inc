<?php

/**
 * @file
 * Growroom group membership relationship handler.
 */

/**
 * Growroom group membership relationship handler.
 *
 * Create a relationship between a growroom_asset, and it's most recent log that
 * assigns group membership, in order to determine its current group.
 *
 * @see growroom_log_handler_relationship_asset
 */
class growroom_group_handler_relationship_membership extends growroom_log_handler_relationship_asset {

  /**
   * {@inheritdoc}
   */
  protected function build_query($asset_id, $time, $done) {
    return growroom_group_asset_membership_query($asset_id, $time, $done, TRUE, 'membership_id');
  }

}
