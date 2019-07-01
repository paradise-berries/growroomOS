<?php
/**
 * @file
 * growroom_log_observation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function growroom_log_observation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function growroom_log_observation_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_log_type().
 */
function growroom_log_observation_default_log_type() {
  $items = array();
  $items['growroom_observation'] = entity_import('log_type', '{
    "type" : "growroom_observation",
    "label" : "Observation",
    "weight" : 0,
    "name_pattern" : "Observation: [log:field-growroom-asset] [log:field-growroom-area] [log:timestamp:short]",
    "name_edit" : "1",
    "done" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
