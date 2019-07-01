<?php
/**
 * @file
 * growroom_map.default_openlayers_layers.inc
 */

/**
 * Implements hook_default_openlayers_layers().
 */
function growroom_map_default_openlayers_layers() {
  $export = array();

  // Google Hybrid layer.
  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'growroom_map_layer_google_hybrid';
  $ol_layer->name = 'Google Hybrid';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Tile';
  $ol_layer->options = array(
    'source' => 'growroom_map_source_google_hybrid',
    'visible' => 1,
    'opacity' => 1,
    /**
     * @todo
     * https://www.drupal.org/node/2543130
     */
    'type' => 'base',
  );
  $export['growroom_map_layer_google_hybrid'] = $ol_layer;

  // Google Satellite layer.
  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'growroom_map_layer_google_satellite';
  $ol_layer->name = 'Google Satellite';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Tile';
  $ol_layer->options = array(
    'source' => 'growroom_map_source_google_satellite',
    'visible' => 1,
    'opacity' => 1,
    /**
     * @todo
     * https://www.drupal.org/node/2543130
     */
    'type' => 'base',
  );
  $export['growroom_map_layer_google_satellite'] = $ol_layer;

  // Google Terrain layer.
  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'growroom_map_layer_google_terrain';
  $ol_layer->name = 'Google Terrain';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Tile';
  $ol_layer->options = array(
    'source' => 'growroom_map_source_google_terrain',
    'visible' => 1,
    'opacity' => 1,
    /**
     * @todo
     * https://www.drupal.org/node/2543130
     */
    'type' => 'base',
  );
  $export['growroom_map_layer_google_terrain'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'growroom_map_layer_openstreetmap';
  $ol_layer->name = 'OpenStreetMap';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Tile';
  $ol_layer->options = array(
    'source' => 'growroom_map_source_openstreetmap',
    'visible' => 1,
    /**
     * @todo
     * https://www.drupal.org/node/2543130
     */
    'type' => 'base',
  );
  $export['growroom_map_layer_openstreetmap'] = $ol_layer;

  // Base layer group.
  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'growroom_map_layer_group';
  $ol_layer->name = 'Growroom Map Layer Group';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Group';
  $ol_layer->options = array(
    'source' => '',
    'visible' => 1,
    'grouptitle' => 'Base layers',
    'grouplayers' => array(
      0 => 'growroom_map_layer_google_hybrid',
      1 => 'growroom_map_layer_openstreetmap',
      /**
       * @todo
       * https://www.drupal.org/node/2543188
       */
//      2 => 'growroom_map_layer_google_satellite',
//      3 => 'growroom_map_layer_google_terrain',
    ),
  );
  $export['growroom_map_layer_group'] = $ol_layer;

  // Geofield widget layer group.
  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'growroom_map_geofield_widget_layer_group';
  $ol_layer->name = 'Growroom Map Geofield Widget Layer Group';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Group';
  $ol_layer->options = array(
    'source' => '',
    'visible' => 1,
    'grouptitle' => 'Draw',
    'grouplayers' => array(
      'openlayers_geofield_layer_widget',
    ),
  );
  $export['growroom_map_geofield_widget_layer_group'] = $ol_layer;

  // Geofield formatter layer group.
  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'growroom_map_geofield_formatter_layer_group';
  $ol_layer->name = 'Growroom Map Geofield Formatter Layer Group';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Group';
  $ol_layer->options = array(
    'source' => '',
    'visible' => 1,
    'grouptitle' => 'Geometry',
    'grouplayers' => array(
      'openlayers_geofield_layer_formatter',
    ),
  );
  $export['growroom_map_geofield_formatter_layer_group'] = $ol_layer;

  return $export;
}

/**
 * Implements hook_default_openlayers_layers_alter().
 */
function growroom_map_default_openlayers_layers_alter(&$layers) {

  // Override the styles of the Geofield Widget and Formatter layers.
  if (!empty($layers['openlayers_geofield_layer_widget'])) {
    $layers['openlayers_geofield_layer_widget']->options['style'] = 'growroom_map_style_geofield';
  }
  if (!empty($layers['openlayers_geofield_layer_formatter'])) {
    $layers['openlayers_geofield_layer_formatter']->options['style'] = 'growroom_map_style_geofield';
  }

  // Move the default map base layer to the top.
  $base_layer = variable_get('growroom_map_default_base_layer', NULL);
  if (!empty($base_layer) && !empty($layers['growroom_map_layer_group'])) {
    $grouplayers = &$layers['growroom_map_layer_group']->options['grouplayers'];
    $key = array_search($base_layer, $grouplayers);
    if ($key !== FALSE) {
      unset($grouplayers[$key]);
      array_unshift($grouplayers, $base_layer);
    }
  }
}
