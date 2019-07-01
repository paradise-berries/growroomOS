<?php
/**
 * @file
 * growroom_maintenance.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function growroom_maintenance_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function growroom_maintenance_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_growroom_plan_type().
 */
function growroom_maintenance_default_growroom_plan_type() {
  $items = array();
  $items['maintenance'] = entity_import('growroom_plan_type', '{
    "type" : "maintenance",
    "label" : "Maintenance Management Plan",
    "weight" : 0,
    "rdf_mapping" : []
  }');
  return $items;
}
