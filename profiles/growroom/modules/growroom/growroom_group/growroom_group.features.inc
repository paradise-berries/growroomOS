<?php
/**
 * @file
 * growroom_group.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function growroom_group_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function growroom_group_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_growroom_asset_type().
 */
function growroom_group_default_growroom_asset_type() {
  $items = array();
  $items['group'] = entity_import('growroom_asset_type', '{ "type" : "group", "label" : "Group", "weight" : 0, "rdf_mapping" : [] }');
  return $items;
}
