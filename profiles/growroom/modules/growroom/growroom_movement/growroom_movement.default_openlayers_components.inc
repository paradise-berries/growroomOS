<?php
/**
 * @file
 * growroom_movement.default_openlayers_components.inc
 */

/**
 * Implements hook_default_openlayers_components().
 */
function growroom_movement_default_openlayers_components() {
  $export = array();

  // Get growroom asset types.
  $asset_types = growroom_asset_types();

  // Create an array of sources to zoom to.
  $sources = array();
  foreach ($asset_types as $type => $info) {
    $source = 'growroom_asset_full_source_' . $type;
    $sources[$source] = $source;
  }

  // Define a zoom-to-source component that applies to all asset sources.
  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default ol_component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'growroom_asset_component_assets_zoom_to_source';
  $ol_component->name = 'Growroom Asset: Assets Zoom to Source';
  $ol_component->description = 'Automatically zoom to the asset source when the map is first built.';
  $ol_component->factory_service = 'openlayers.Component:ZoomToSource';
  $ol_component->options = array(
    'source' => $sources,
    'duration' => 500,
    'zoom' => 'auto',
    'max_zoom' => 20,
    'process_once' => 0,
  );
  $export['growroom_asset_component_assets_zoom_to_source'] = $ol_component;

  // Create an array of layers to enable popups on.
  $layers = array();
  foreach ($asset_types as $type => $info) {
    $layer = 'growroom_asset_cluster_layer_' . $type;
    $layers[$layer] = $layer;
  }

  // Create a popup component for cluster layers.
  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default ol_component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'growroom_asset_component_assets_popup';
  $ol_component->name = 'Growroom Asset: Assets Popup';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:Popup';
  $ol_component->options = array(
    'frontend_layers' => $layers,
    'positioning' => 'top-right',
    'autoPan' => TRUE,
    'autoPanAnimation' => 0,
    'autoPanMargin' => 20,
    'closer' => 1,
  );
  $export['growroom_asset_component_assets_popup'] = $ol_component;

  return $export;
}
