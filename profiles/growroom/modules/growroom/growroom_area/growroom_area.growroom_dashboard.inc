<?php
/**
 * @file
 * Growroom dashboard hooks implemented by growroom calendar module.
 */

/**
 * Implements hook_growroom_dashboard_panes().
 */
function growroom_area_growroom_dashboard_panes() {
  return array(
    'growroom_area_map' => array(
      'title' => t('Map'),
      'callback' => 'growroom_area_dashboard_map',
      'group' => 'map',
    ),
  );
}

/**
 * Date dashboard callback.
 */
function growroom_area_dashboard_map() {
  $build = growroom_map_build('growroom_areas');
  return drupal_render($build);
}
