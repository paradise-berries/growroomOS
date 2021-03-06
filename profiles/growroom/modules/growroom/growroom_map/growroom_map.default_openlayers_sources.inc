<?php
/**
 * @file
 * growroom_map.default_openlayers_sources.inc
 */

/**
 * Implements hook_default_openlayers_sources().
 */
function growroom_map_default_openlayers_sources() {
  $export = array();

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'growroom_map_source_google_hybrid';
  $ol_source->name = 'Growroom Map: Google Hybrid';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:GoogleMaps';
  $ol_source->options = array(
    'key' => variable_get('growroom_map_google_api_key', ''),
    'client' => '',
    'channel' => '',
    'mapTypeId' => 'HYBRID',
    'sensor' => 0,
  );
  $export['growroom_map_source_google_hybrid'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'growroom_map_source_google_satellite';
  $ol_source->name = 'Growroom Map: Google Satellite';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:GoogleMaps';
  $ol_source->options = array(
    'key' => variable_get('growroom_map_google_api_key', ''),
    'client' => '',
    'channel' => '',
    'mapTypeId' => 'SATELLITE',
    'sensor' => 0,
  );
  $export['growroom_map_source_google_satellite'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'growroom_map_source_google_terrain';
  $ol_source->name = 'Growroom Map: Google Terrain';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:GoogleMaps';
  $ol_source->options = array(
    'key' => variable_get('growroom_map_google_api_key', ''),
    'client' => '',
    'channel' => '',
    'mapTypeId' => 'TERRAIN',
    'sensor' => 0,
  );
  $export['growroom_map_source_google_terrain'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'growroom_map_source_openstreetmap';
  $ol_source->name = 'Growroom Map: OpenStreetMap';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:OSM';
  $ol_source->options = array();
  $export['growroom_map_source_openstreetmap'] = $ol_source;

  return $export;
}
