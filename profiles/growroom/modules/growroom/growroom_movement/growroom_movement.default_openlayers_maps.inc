<?php
/**
 * @file
 * growroom_movement.default_openlayers_maps.inc
 */

/**
 * Implements hook_default_openlayers_maps().
 */
function growroom_movement_default_openlayers_maps() {
  $export = array();

  // Get growroom asset types.
  $asset_types = growroom_asset_types();

  // Create a map for each asset type.
  foreach ($asset_types as $key => $type) {

    // Generate a machine name.
    $machine_name = 'growroom_assets_' . $key;

    // Build the map.
    $ol_map = new stdClass();
    $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
    $ol_map->api_version = 1;
    $ol_map->machine_name = $machine_name;
    $ol_map->name = 'Growroom Assets: ' . $type->label;
    $ol_map->description = '';
    $ol_map->factory_service = 'openlayers.Map:OLMap';
    $ol_map->options = array(
      'width' => 'auto',
      'height' => '500px',
      'provideBlockLayerSwitcher' => 0,
      'view' => array(
        'center' => array(
          'lat' => 0,
          'lon' => 0,
        ),
        'rotation' => 0,
        'zoom' => 2,
        'minZoom' => 0,
        'maxZoom' => 24,
      ),
      'renderer' => 'canvas',
      'layers' => array(
        0 => 'growroom_asset_cluster_layer_' . $key,
        1 => 'growroom_asset_full_layer_' . $key,
        2 => 'growroom_area_layer_areas_group',
      ),
      'controls' => array(
        0 => 'openlayers_control_zoom',
        1 => 'openlayers_control_scaleline',
        2 => 'growroom_map_control_layer_switcher',
        3 => 'growroom_map_control_geolocate',
        4 => 'growroom_map_control_geocoder',
      ),
      'interactions' => array(
        0 => 'openlayers_interaction_doubleclickzoom',
        1 => 'openlayers_interaction_dragpan',
        2 => 'openlayers_interaction_mousewheelzoom',
        3 => 'openlayers_interaction_pinchzoom',
      ),
      'components' => array(
        0 => 'growroom_asset_component_assets_zoom_to_source',
        1 => 'growroom_asset_component_assets_popup',
        2 => 'growroom_map_component_progress_bar',
      ),
    );

    // Add the map to the export.
    $export[$machine_name] = $ol_map;
  }

  return $export;
}
