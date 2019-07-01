<?php
/**
 * @file
 * growroom_map.default_openlayers_styles.inc
 */

/**
 * Implements hook_default_openlayers_styles().
 */
function growroom_map_default_openlayers_styles() {
  $export = array();

  // Define the growroom styles.
  $styles = array(
    'growroom_map_style_blue' => array(
      'name' => 'Growroom Blue',
      'color' => 'rgba(51,153,255,1)',
    ),
    'growroom_map_style_dark_green' => array(
      'name' => 'Growroom Dark Green',
      'color' => 'rgba(51,153,51,1)',
    ),
    'growroom_map_style_green' => array(
      'name' => 'Growroom Green',
      'color' => 'rgba(102,204,102,1)',
    ),
    'growroom_map_style_grey' => array(
      'name' => 'Growroom Grey',
      'color' => 'rgba(204,204,204,0.7)',
    ),
    'growroom_map_style_orange' => array(
      'name' => 'Growroom Orange',
      'color' => 'rgba(255,153,51,1)',
    ),
    'growroom_map_style_purple' => array(
      'name' => 'Growroom Purple',
      'color' => 'rgba(204,51,102,1)',
    ),
    'growroom_map_style_red' => array(
      'name' => 'Growroom Red',
      'color' => 'rgba(204,0,0,1)',
    ),
    'growroom_map_style_yellow' => array(
      'name' => 'Growroom Yellow',
      'color' => 'rgba(255,255,51,1)',
    ),
  );

  // Iterate through the defined styles and create them.
  foreach ($styles as $machine_name => $style) {
    $ol_style = new stdClass();
    $ol_style->disabled = FALSE; /* Edit this to true to make a default ol_style disabled initially */
    $ol_style->api_version = 1;
    $ol_style->machine_name = $machine_name;
    $ol_style->name = t($style['name']);
    $ol_style->description = '';
    $ol_style->factory_service = 'openlayers.Style:InlineJS';
    $ol_style->options = array(
      'javascript' => 'var fill = new ol.style.Fill({
  color: "rgba(0,0,0,0)"
});
var stroke = new ol.style.Stroke({
  color: "' . $style['color'] . '",
  width: 2
});
var style = [
  new ol.style.Style({
    image: new ol.style.Circle({
      fill: fill,
      stroke: stroke,
      radius: 4
    }),
    fill: fill,
    stroke: stroke
  })
];
return style;',
    );
    $export[$machine_name] = $ol_style;
  }

  // Add a cluster style type.
  $ol_style = new stdClass();
  $ol_style->disabled = FALSE; /* Edit this to true to make a default ol_style disabled initially */
  $ol_style->api_version = 1;
  $ol_style->machine_name = 'growroom_map_style_cluster';
  $ol_style->name = 'Growroom Cluster';
  $ol_style->description = '';
  $ol_style->factory_service = 'openlayers.Style:Cluster';
  $ol_style->options = array();
  $export['growroom_map_style_cluster'] = $ol_style;

  // Add styles for Geofield editing/viewing.
  $ol_style = new stdClass();
  $ol_style->api_version = 1;
  $ol_style->machine_name = 'growroom_map_style_geofield';
  $ol_style->name = 'Growroom Map Geofield Edit';
  $ol_style->description = '';
  $ol_style->factory_service = 'openlayers.Style:Circle';
  $ol_style->options = array(
    'default' => array(
      'image' => array(
        'radius' => 4,
        'fill' => array(
          'color' => '0, 0, 0, 0',
        ),
        'stroke' => array(
          'color' => '255, 153, 51, 1',
          'width' => 4,
          'lineDash' => '0,0',
        ),
      ),
      'stroke' => array(
        'color' => '255, 153, 51, 1',
        'width' => 4,
        'lineDash' => '0,0',
      ),
      'fill' => array(
        'color' => '0, 0, 0, 0',
      ),
    ),
  );
  $export['growroom_map_style_geofield'] = $ol_style;

  return $export;
}
