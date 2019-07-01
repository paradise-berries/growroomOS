<?php
/**
 * @file
 * Feeds tamper plugins provided by the growroom import module.
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function growroom_import_feeds_tamper_default() {
  $export = array();

  // Load asset types.
  $asset_types = growroom_asset_types();

  // Add asset tamper plugins.
  foreach ($asset_types as $bundle => $type) {

    // Make asset name field required.
    $feeds_tamper = growroom_import_feeds_tamper_plugin('growroom_asset', $bundle, 'Name', 'required');
    $export[$feeds_tamper->id] = $feeds_tamper;

    // Convert archived to boolean.
    $feeds_tamper = growroom_import_feeds_tamper_plugin('growroom_asset', $bundle, 'Archived', 'boolean_default_false');
    $export[$feeds_tamper->id] = $feeds_tamper;

    // If a "Parent IDs" field exists, explode it into an array of IDs.
    if (!empty(field_info_instance('growroom_asset', 'field_growroom_parent', $bundle))) {
      $feeds_tamper = growroom_import_feeds_tamper_plugin('growroom_asset', $bundle, 'Parent IDs', 'explode');
      $export[$feeds_tamper->id] = $feeds_tamper;
    }
  }

  // Load log types.
  $log_types = log_types();

  // Add log tamper plugins.
  foreach ($log_types as $bundle => $type) {

    // Convert date to timestamp.
    $feeds_tamper = growroom_import_feeds_tamper_plugin('log', $bundle, 'Date', 'strtotime');
    $export[$feeds_tamper->id] = $feeds_tamper;

    // Make date field required.
    $feeds_tamper = growroom_import_feeds_tamper_plugin('log', $bundle, 'Date', 'required');
    $feeds_tamper->weight = 1;
    $export[$feeds_tamper->id] = $feeds_tamper;

    // Convert done to boolean.
    $feeds_tamper = growroom_import_feeds_tamper_plugin('log', $bundle, 'Done', 'boolean_default_true');
    $export[$feeds_tamper->id] = $feeds_tamper;

    // If an "Asset IDs" field exists, explode it into an array of IDs.
    if (!empty(field_info_instance('log', 'field_growroom_asset', $bundle))) {
      $feeds_tamper = growroom_import_feeds_tamper_plugin('log', $bundle, 'Asset IDs', 'explode');
      $export[$feeds_tamper->id] = $feeds_tamper;
    }

    // If an "Areas" field exists, explode it into an array of area names.
    if (!empty(field_info_instance('log', 'field_growroom_area', $bundle))) {
      $feeds_tamper = growroom_import_feeds_tamper_plugin('log', $bundle, 'Areas', 'explode');
      $export[$feeds_tamper->id] = $feeds_tamper;
    }

    // If a "Categories" field exists, explode it into an array of category
    // names.
    if (!empty(field_info_instance('log', 'field_growroom_log_category', $bundle))) {
      $feeds_tamper = growroom_import_feeds_tamper_plugin('log', $bundle, 'Categories', 'explode');
      $export[$feeds_tamper->id] = $feeds_tamper;
    }
  }

  return $export;
}
