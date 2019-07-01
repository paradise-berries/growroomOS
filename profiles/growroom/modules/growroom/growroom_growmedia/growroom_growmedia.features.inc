<?php
/**
 * @file
 * growroom_growmedia.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function growroom_growmedia_ctools_plugin_api($module = NULL, $api = NULL) {
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
function growroom_growmedia_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_growroom_asset_type().
 */
function growroom_growmedia_default_growroom_asset_type() {
  $items = array();
  $items['growmedia'] = entity_import('growroom_asset_type', '{
    "type" : "growmedia",
    "label" : "GrowMedia",
    "weight" : 0,
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_log_type().
 */
function growroom_growmedia_default_log_type() {
  $items = array();
  $items['growroom_substrate'] = entity_import('log_type', '{
    "type" : "growroom_substrate",
    "label" : "Substrate",
    "weight" : 0,
    "name_pattern" : "Substrate: [log:field-growroom-asset]",
    "name_edit" : "1",
    "done" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
