<?php
/**
 * @file
 * growroom_mapknitter.default_openlayers_maps.inc
 */

/**
 * Implements hook_default_openlayers_maps_alter().
 */
function growroom_mapknitter_default_openlayers_maps_alter(&$maps) {

  // Load the MapKnitter slug.
  $slug = variable_get('growroom_mapknitter_slug', '');

  // If the slug is blank, bail.
  if (empty($slug)) {
    return;
  }

  // Add the MapKnitter layer group to growroom maps.
  $growroom_maps = array(
    'growroom_areas',
    'growroom_map_geofield',
    'growroom_map_geofield_formatter',
  );

  // Iterate over the growroom maps and see if they exist.
  foreach ($growroom_maps as $growroom_map) {

    // If this map exists in the list of existing maps...
    if (array_key_exists($growroom_map, $maps)) {

      // Add the MapKnitter layer group.
      $maps[$growroom_map]->options['layers'][] = 'growroom_mapknitter_layer_group';
    }
  }
}
