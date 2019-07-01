<?php
/**
 * @file
 * growroom_agents.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function growroom_agents_ctools_plugin_api($module = NULL, $api = NULL) {
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
function growroom_agents_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_growroom_asset_type().
 */
function growroom_agents_default_growroom_asset_type() {
  $items = array();
  $items['agents'] = entity_import('growroom_asset_type', '{
    "type" : "agents",
    "label" : "Agents",
    "weight" : 0,
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_log_type().
 */
function growroom_agents_default_log_type() {
  $items = array();
  $items['growroom_agent'] = entity_import('log_type', '{
    "type" : "growroom_agent",
    "label" : "Agent",
    "weight" : 0,
    "name_pattern" : "Agent: [log:field-growroom-asset]",
    "name_edit" : "1",
    "done" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
