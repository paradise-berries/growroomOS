<?php
/**
 * @file
 * growroom_mapknitter.default_openlayers_layers.inc
 */

/**
 * Implements hook_default_openlayers_layers().
 */
function growroom_mapknitter_default_openlayers_layers() {
  $export = array();

  // Load the MapKnitter slug and title.
  $slug = variable_get('growroom_mapknitter_slug', '');
  $title = variable_get('growroom_mapknitter_title', '');

  // If the slug or title is empty, bail.
  if (empty($slug) || empty($title)) {
    return $export;
  }

  // Add a MapKnitter layer.
  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'growroom_mapknitter_layer';
  $ol_layer->name = check_plain($title);
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Tile';
  $ol_layer->options = array(
    'source' => 'growroom_mapknitter_source',
    'visible' => 1,
  );
  $export['growroom_mapknitter_layer'] = $ol_layer;

  // Add a layer group for MapKnitter layers.
  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'growroom_mapknitter_layer_group';
  $ol_layer->name = 'Growroom MapKnitter Layer Group';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Group';
  $ol_layer->options = array(
    'source' => '',
    'visible' => 1,
    'grouptitle' => 'MapKnitter layers',
    'grouplayers' => array(
      'growroom_mapknitter_layer',
    ),
  );
  $export['growroom_mapknitter_layer_group'] = $ol_layer;

  return $export;
}
