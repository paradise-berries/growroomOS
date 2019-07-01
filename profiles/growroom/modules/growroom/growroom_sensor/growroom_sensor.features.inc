<?php
/**
 * @file
 * growroom_sensor.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function growroom_sensor_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function growroom_sensor_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_growroom_asset_type().
 */
function growroom_sensor_default_growroom_asset_type() {
  $items = array();
  $items['sensor'] = entity_import('growroom_asset_type', '{
    "type" : "sensor",
    "label" : "Sensor",
    "weight" : 0,
    "rdf_mapping" : []
  }');
  return $items;
}
