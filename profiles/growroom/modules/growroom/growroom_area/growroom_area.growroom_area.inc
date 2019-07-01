<?php
/**
 * @file
 * Growroom Area hooks implemented by the Growroom Area module.
 */

/**
 * Implements hook_growroom_area_type_info().
 */
function growroom_area_growroom_area_type_info() {
  return array(
    'other' => array(
      'label' => t('Other'),
      'style' => 'growroom_map_style_blue',
      'weight' => 150,
    ),
    'storage' => array(
      'label' => t('Storage'),
      'style' => 'growroom_map_style_red',
      'weight' => 150,
    ),
    'processing' => array(
      'label' => t('Processing'),
      'style' => 'growroom_map_style_red',
      'weight' => 150,    ),
  );
}

/**
 * Implements hook_growroom_area_details().
 */
function growroom_area_growroom_area_details($id) {

  // Start a render array.
  $output = array();

  // Display the calculated area (formatted).
  $calculated_area = growroom_area_calculate_area($id, TRUE);
  if (!empty($calculated_area)) {
    $output['calculated_area'] = array(
      '#type' => 'markup',
      '#markup' => '<p><small>Calculated area: ' . $calculated_area . '</small></p>',
      '#weight' => -100,
    );
  }

  // Return the render array.
  return $output;
}

/**
 * Implements hook_growroom_area_details().
 */
function growroom_flags_growroom_area_details($id) {

  // Start a render array.
  $output = array();

  // Load the area.
  $area = taxonomy_term_load($id);

  // If the area didn't load, bail.
  if (empty($area)) {
    return $output;
  }

  // Load and display any flags on the area.
  $all_flags = growroom_flags_list();
  $area_flags = growroom_flags_load($area);
  foreach ($area_flags as $key => $flag) {
    if (!empty($all_flags[$flag])) {
      $area_flags[$key] = growroom_flags_wrap($all_flags[$flag], $flag);
    }
  }

  // If there are no flags, bail.
  if (empty($area_flags)) {
    return $output;
  }

  // Add the list of flags to the area details.
  $output[] = array(
    '#type' => 'markup',
    '#markup' => implode(' ', $area_flags),
    '#weight' => -101,
  );

  // Return the output.
  return $output;
}
