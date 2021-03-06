<?php
/**
 * @file
 * growroom_water_test.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function growroom_water_test_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function growroom_water_test_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_log_type().
 */
function growroom_water_test_default_log_type() {
  $items = array();
  $items['growroom_water_test'] = entity_import('log_type', '{
    "type" : "growroom_water_test",
    "label" : "Water Test",
    "weight" : 0,
    "name_pattern" : "Water test: [log:field-growroom-area]",
    "name_edit" : "1",
    "done" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
