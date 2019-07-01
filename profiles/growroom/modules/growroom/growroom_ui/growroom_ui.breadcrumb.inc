<?php
/**
 * Breadcrumb code for the Growroom UI module.
 */

/**
 * Helper function for altering the breadcrumb.
 */
function _growroom_ui_menu_breadcrumb_alter(&$active_trail, $item) {

  // If the current path contains /growroom, and there are more than 2 trail items:
  if (strpos($item['path'], 'growroom') === 0 && count($active_trail) > 2) {

    // If the link to /growroom already exists in the second position, bail.
    if (!empty($active_trail[1]['link_path']) && $active_trail[1]['link_path'] == 'growroom') {
      return;
    }

    // Add an item for /growroom.
    $start = array_shift($active_trail);
    $growroom_item = menu_get_item('growroom');
    array_unshift($active_trail, $growroom_item);
    array_unshift($active_trail, $start);
  }
}

/**
 * Set the breadcrumb for an entity view page. This should be called in
 * hook_entity_view().
 *
 * @param $entity_type
 *   The entity type.
 * @param $bundle
 *   The entity bundle.
 *
 * @see growroom_ui_entity_view()
 */
function growroom_ui_entity_set_breadcrumb($entity_type, $bundle) {

  // Get the breadcrumb from our helper function.
  $breadcrumb = growroom_ui_entity_type_breadcrumb($entity_type, $bundle);

  // Add base breadcrumb items to the front.
  $base = array(
    l(t('Home'), '<front>'),
    l(t('Growroom'), 'growroom'),
  );
  $breadcrumb = array_merge($base, $breadcrumb);

  // Set the breadcrumb.
  drupal_set_breadcrumb($breadcrumb);
}

/**
 * Build breadcrumbs for a specific entity type and bundle.
 *
 * @param $type
 *   The entity type.
 * @param $bundle
 *   The bundle.
 *
 * @return array
 *   Returns a breadcrumb array.
 */
function growroom_ui_entity_type_breadcrumb($type, $bundle) {

  // Start an empty breadcrumb array.
  $breadcrumb = array();

  // Load entity UI information.
  $ui_info = growroom_ui_entities($type, $bundle);

  // Get the label (plural). Bail if it's not set.
  if (empty($ui_info['label_plural'])) {
    return $breadcrumb;
  }
  $label = $ui_info['label_plural'];

  // If the entity type has a View, load the path.
  if (!empty($ui_info['view'])) {
    $path = growroom_ui_view_page_path($ui_info['view']);
  }

  // If this is a growroom_asset entity, add a link to the full assets list.
  if ($type == 'growroom_asset') {
    $breadcrumb[] = l(t('Assets'), 'growroom/assets');
  }

  // Or, if this is a growroom_plan entity, add a link to the full plans list.
  elseif ($type == 'growroom_plan') {
    $breadcrumb[] = l(t('Plans'), 'growroom/plans');
  }

  // Or, if this is a log entity, add a link to the full logs list.
  elseif ($type == 'log') {
    $breadcrumb[] = l(t('Logs'), 'growroom/logs');
  }

  // If this is a taxonomy_term entity, and it is linked to a specific asset
  // type, add the asset breadcrumb trail (recurse into this function again).
  if ($type == 'taxonomy_term' && !empty($ui_info['growroom_asset'])) {
    $asset_breadcrumbs = growroom_ui_entity_type_breadcrumb('growroom_asset', $ui_info['growroom_asset']);
    $breadcrumb = array_merge($asset_breadcrumbs, $breadcrumb);
  }

  // If a path was found, add a link to the breadcrumb. Otherwise, add a simple
  // text breadcrumb.
  if (!empty($path)) {
    $breadcrumb[] = l($label, $path);
  }
  else {
    $breadcrumb[] = $label;
  }

  // If this is a taxonomy_term entity, get the default breadcrumb and tack it
  // onto the end, so we can take advantage of the structure already provided
  // by the taxonomy hierarchy. Shift the first item off (home) because we've
  // started a new breadcrumb from scratch.
  if ($type == 'taxonomy_term') {
    $default_breadcrumb = drupal_get_breadcrumb();
    array_shift($default_breadcrumb);
    $breadcrumb = array_merge($breadcrumb, $default_breadcrumb);
  }

  // Return the breadcrumb.
  return $breadcrumb;
}
