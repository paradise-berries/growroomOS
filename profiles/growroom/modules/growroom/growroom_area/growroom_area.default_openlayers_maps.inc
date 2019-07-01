<?php
/**
 * @file
 * growroom_area.default_openlayers_maps.inc
 */

/**
 * Implements hook_default_openlayers_maps().
 */
function growroom_area_default_openlayers_maps() {
  $export = array();

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'growroom_areas';
  $ol_map->name = 'Growroom Areas';
  $ol_map->description = 'A map of all growroom areas, color-coded by type.';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '500px',
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
      0 => 'growroom_area_layer_group',
    ),
    'controls' => array(
      0 => 'openlayers_control_zoom',
      1 => 'openlayers_control_scaleline',
      2 => 'growroom_map_control_layer_switcher',
      3 => 'growroom_map_control_geolocate',
      4 => 'growroom_map_control_geocoder',
      /**
       * @todo
       * https://www.drupal.org/node/2543186
       */
//      5 => 'openlayers_control_fullscreen',
    ),
    'components' => array(
      0 => 'growroom_area_component_areas_zoom_to_source',
      1 => 'growroom_area_component_area_details_popup',
      2 => 'growroom_map_component_progress_bar',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
      3 => 'openlayers_interaction_pinchzoom',
    ),
  );
  $export['growroom_areas'] = $ol_map;

  return $export;
}

/**
 * Implements hook_default_openlayers_maps_alter().
 */
function growroom_area_default_openlayers_maps_alter(&$maps) {

  // Add "all areas" group layer to growroom_geofield* maps.
  foreach ($maps as &$map) {
    if (substr($map->machine_name, 0, 17) == 'growroom_map_geofield') {
      $map->options['layers'][] = 'growroom_area_layer_areas_group';
    }
  }
}
