<?php

/**
 * @file
 * Growroom
  Area hooks implemented by the Growroom Area Types module.
 */

/**
 * Implements hook_growroom_area_type_info().
 */
function growroom_area_types_growroom_area_type_info() {
  return array(
    'pot' => array(
      'label' => t('Pot'),
      'style' => 'growroom_map_style_red',
      'weight' => 10,
    ),
    'port' => array(
      'label' => t('Port'),
      'style' => 'growroom_map_style_red',
      'weight' => 10,
    ),
    'tube' => array(
      'label' => t('Tube'),
      'style' => 'growroom_map_style_yellow',
      'weight' => 10,
    ),
    'tower' => array(
      'label' => t('Tower'),
      'style' => 'growroom_map_style_yellow',
      'weight' => 10,
    ),
    'tray' => array(
      'label' => t('Tray'),
      'style' => 'growroom_map_style_yellow',
      'weight' => 10,
    ),
    'shelf' => array(
      'label' => t('Shelf'),
      'style' => 'growroom_map_style_purple',
      'weight' => 10,
    ),
    'rack' => array(
      'label' => t('Rack'),
      'style' => 'growroom_map_style_blue',
      'weight' => 10,
    ),
    'bed' => array(
      'label' => t('Bed'),
      'style' => 'growroom_map_style_blue',
      'weight' => 10,
    ),
    'row' => array(
      'label' => t('Row'),
      'style' => 'growroom_map_style_blue',
      'weight' => 10,
    ),
    'tank' => array(
      'label' => t('Tank'),
      'style' => 'growroom_map_style_blue',
      'weight' => 10,
    ),
    'zone' => array(
      'label' => t('Zone'),
      'style' => 'growroom_map_style_blue',
      'weight' => 50,
      ),
    'growroom' => array(
      'label' => t('GrowRoom'),
      'style' => 'growroom_map_style_green',
      'weight' => 100,
     ),
      'greenhouse' => array(
      'label' => t('Greenhouse'),
      'style' => 'growroom_map_style_green',
      'weight' => 100,
    ),
  );
}
