<?php
/**
 * @file
 * growroom_movement.default_openlayers_sources.inc
 */

/**
 * Implements hook_default_openlayers_sources().
 */
function growroom_movement_default_openlayers_sources() {
  $export = array();

  // Load all available growroom asset types.
  $asset_types = growroom_asset_types();

  // Iterate through the available types, and add a source for each one.
  foreach ($asset_types as $key => $type) {

    // Generate a machine name for the full geometry source.
    $full_source_name = 'growroom_asset_full_source_' . $key;

    // Build the full geometry source.
    $ol_source = new stdClass();
    $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
    $ol_source->api_version = 1;
    $ol_source->machine_name = $full_source_name;
    $ol_source->name = 'Growroom Assets: ' . $type->label . ' (full geometry)';
    $ol_source->description = 'This source is automatically generated by the Growroom Log module.';
    $ol_source->factory_service = 'openlayers.Source:GeoJSON';
    $ol_source->options = array(
      'url' => 'growroom/assets/geojson/full/' . $key,
      'useBBOX' => 0,
      'paramForwarding' => 1,
      'reloadOnZoomChange' => 0,
      'reloadOnExtentChange' => 0,
      'geojson_data' => '',
    );
    $export[$full_source_name] = $ol_source;

    // Generate a machine name for the centroid source.
    $centroid_source_name = 'growroom_asset_centroid_source_' . $key;

    // Build the centroid source.
    $ol_source = new stdClass();
    $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
    $ol_source->api_version = 1;
    $ol_source->machine_name = $centroid_source_name;
    $ol_source->name = 'Growroom Assets: ' . $type->label . ' (centroid)';
    $ol_source->description = 'This source is automatically generated by the Growroom Log module.';
    $ol_source->factory_service = 'openlayers.Source:GeoJSON';
    $ol_source->options = array(
      'url' => 'growroom/assets/geojson/centroid/' . $key,
      'useBBOX' => 0,
      'paramForwarding' => 1,
      'reloadOnZoomChange' => 0,
      'reloadOnExtentChange' => 0,
      'geojson_data' => '',
    );
    $export[$centroid_source_name] = $ol_source;

    // Generate a machine name for the cluster source.
    $cluster_source_name = 'growroom_asset_cluster_source_' . $key;

    // Build the cluster source.
    $ol_source = new stdClass();
    $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
    $ol_source->api_version = 1;
    $ol_source->machine_name = $cluster_source_name;
    $ol_source->name = 'Growroom Assets: ' . $type->label . ' (cluster)';
    $ol_source->description = '';
    $ol_source->factory_service = 'openlayers.Source:Cluster';
    $ol_source->options = array(
      'source' => $centroid_source_name,
      'distance' => '50',
    );
    $export[$cluster_source_name] = $ol_source;
  }

  return $export;
}
