<?php
/**
 * @file
 * growroom_log_activity.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function growroom_log_activity_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function growroom_log_activity_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_log_type().
 */
function growroom_log_activity_default_log_type() {
  $items = array();
  $items['growroom_activity'] = entity_import('log_type', '{
    "type" : "growroom_activity",
    "label" : "Activity",
    "weight" : 0,
    "name_pattern" : "Activity: [log:field-growroom-asset] [log:field-growroom-area]",
    "name_edit" : "1",
    "done" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
