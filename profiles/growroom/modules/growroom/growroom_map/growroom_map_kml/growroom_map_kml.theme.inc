<?php

/**
 * @file
 * Growroom map theme functions.
 */

/**
 * Template preprocessor for growroom map KML output.
 */
function template_preprocess_growroom_map_kml(&$vars) {

  // If content is not set, initialize it as an empty string.
  if (!isset($vars['content'])) {
    $vars['content'] = '';
  }

  // Add placemarks to the content.
  foreach ($vars['placemarks'] as $placemark) {
    $vars['content'] .= theme('growroom_map_kml_placemark', $placemark);
  }
}

/**
 * Template preprocessor for growroom map KML placemark output.
 */
function template_preprocess_growroom_map_kml_placemark(&$vars) {

  // If KML is not set, initialize it as an empty string.
  if (!isset($vars['kml'])) {
    $vars['kml'] = '';
  }

  // If there is a geometry, convert it to KML and append it.
  if (!empty($vars['geometry'])) {

    // Load GeoPHP.
    geophp_load();

    // Create a geometry object.
    $geometry = geoPHP::load($vars['geometry'], 'wkt');

    // Convert the geometry to KML.
    $kml = $geometry->out('kml');

    // Append the KML to the output.
    $vars['kml'] .= $kml . "\n";
  }
}
