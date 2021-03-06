<?php

/**
 * @file
 * Growroom fields views data.
 */

/**
 * Implements hook_field_views_data_alter().
 */
function growroom_fields_field_views_data_alter(&$result, $field, $module) {

  // Replace the filter handler for field_growroom_log_owner fields so that we can
  // expose a select list of user options.
  $owner_field = 'field_growroom_log_owner';
  if ($field['field_name'] == $owner_field) {
    if (!empty($result['field_data_' . $owner_field][$owner_field . '_target_id']['filter'])) {
      $filter = &$result['field_data_' . $owner_field][$owner_field . '_target_id']['filter'];
      $filter['handler'] = 'growroom_fields_handler_filter_log_owner';
    }
  }
}
