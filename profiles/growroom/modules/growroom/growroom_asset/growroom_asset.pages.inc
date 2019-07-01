<?php

/**
 * @file
 * Growroom asset pages.
 */

/**
 * Asset view callback.
 *
 * @param GrowroomAsset $growroom_asset
 *   The growroom asset entity.
 *
 * @return array
 *   Returns the entity render array.
 */
function growroom_asset_view(GrowroomAsset $growroom_asset) {

  // Set the page title.
  drupal_set_title(entity_label('growroom_asset', $growroom_asset));

  // Build the asset's render array.
  $build = entity_view('growroom_asset', array(entity_id('growroom_asset', $growroom_asset) => $growroom_asset), 'full');

  // Return the render array.
  return $build;
}

/**
 * Page to select asset type to add new asset.
 */
function growroom_asset_add_types_page() {
  $items = array();
  foreach (growroom_asset_types() as $growroom_asset_type_key => $growroom_asset_type) {
    if (growroom_asset_access('create', $growroom_asset_type)) {
      $items[] = l(entity_label('growroom_asset_type', $growroom_asset_type), 'growroom/asset/add/' . $growroom_asset_type_key);
    }
  }
  return array(
    'list' => array(
      '#theme' => 'item_list',
      '#items' => $items,
      '#title' => t('Select a type of asset to create.'),
    ),
  );
}

/**
 * Add new asset page callback.
 *
 * @param string $type
 *   The growroom asset type.
 *
 * @return array
 *   Returns a form array.
 */
function growroom_asset_add($type) {
  $growroom_asset_type = growroom_asset_types($type);

  $growroom_asset = entity_create('growroom_asset', array('type' => $type));
  drupal_set_title(t('Add @name', array('@name' => entity_label('growroom_asset_type', $growroom_asset_type))));

  $output = drupal_get_form('growroom_asset_form', $growroom_asset);

  return $output;
}

/**
 * Asset form.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 * @param GrowroomAsset $growroom_asset
 *   The growroom asset entity.
 *
 * @return array
 *   Returns a form array.
 */
function growroom_asset_form(array $form, array &$form_state, GrowroomAsset $growroom_asset) {

  $form['growroom_asset'] = array(
    '#type' => 'value',
    '#value' => $growroom_asset,
  );

  // Load the asset type.
  $growroom_asset_type = growroom_asset_type_load($growroom_asset->type);

  // Asset name.
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('Give this %type asset a name.', array('%type' => $growroom_asset_type->label)),
    '#default_value' => $growroom_asset->name,
    '#required' => TRUE,
    '#weight' => -100,
  );

  // Additional settings (vertical tabs at the bottom of the form).
  $form['additional_settings'] = array(
    '#type' => 'vertical_tabs',
    '#weight' => 99,
  );

  // Asset archived status.
  $archived_boolean = FALSE;
  $archived_date = '';
  if (!empty($growroom_asset->archived)) {
    $archived_boolean = TRUE;
    $archived_date = ' (' . format_date($growroom_asset->archived) . ')';
  }
  $form['asset_status'] = array(
    '#type' => 'fieldset',
    '#title' => t('Asset status'),
    '#description' => t('Archive this asset. Archived assets will not show in most lists, but will be visible in archives.'),
    '#collapsible' => TRUE,
    '#group' => 'additional_settings',
  );
  $form['asset_status']['archived_boolean'] = array(
    '#type' => 'checkbox',
    '#title' => t('Archived') . $archived_date,
    '#default_value' => $archived_boolean,
  );
  $form['asset_status']['archived'] = array(
    '#type' => 'value',
    '#value' => $growroom_asset->archived,
  );

  // Asset user id.
  $form['uid'] = array(
    '#type' => 'value',
    '#value' => $growroom_asset->uid,
  );

  field_attach_form('growroom_asset', $growroom_asset, $form, $form_state);

  $form['actions'] = array(
    '#weight' => 100,
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#validate' => array('growroom_asset_form_validate'),
    '#submit' => array('growroom_asset_form_submit'),
  );

  // Show Delete button if allowed.
  $growroom_asset_id = entity_id('growroom_asset', $growroom_asset);
  if (!empty($growroom_asset_id) && growroom_asset_access('delete', $growroom_asset)) {

    // Get the destination query parameter. If it is the current path, change
    // to <front> (because the current path won't exist once the asset is
    // deleted).
    $destination = drupal_get_destination();
    if ($destination['destination'] == current_path()) {
      $destination['destination'] = '<front>';
    }
    $form['actions']['delete'] = array(
      '#type' => 'markup',
      '#markup' => l(t('Delete'), 'growroom/asset/' . $growroom_asset_id . '/delete', array('query' => $destination)),
    );
  }

  return $form;
}

/**
 * Asset validate handler.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 */
function growroom_asset_form_validate(array $form, array &$form_state) {

  // If the 'archived_boolean' checkbox has changed, update the asset.
  if ($form_state['values']['archived_boolean'] != $form['asset_status']['archived_boolean']['#default_value']) {

    // If it is checked, set the asset's archived date to current timestamp.
    if (!empty($form_state['values']['archived_boolean'])) {
      $form_state['values']['archived'] = REQUEST_TIME;
    }

    // Otherwise, set the asset's archived date to NULL.
    else {
      $form_state['values']['archived'] = NULL;
    }
  }
}

/**
 * Asset submit handler.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 */
function growroom_asset_form_submit(array $form, array &$form_state) {
  $growroom_asset = $form_state['values']['growroom_asset'];

  entity_form_submit_build_entity('growroom_asset', $growroom_asset, $form, $form_state);

  growroom_asset_save($growroom_asset);

  $growroom_asset_uri = entity_uri('growroom_asset', $growroom_asset);

  $form_state['redirect'] = $growroom_asset_uri['path'];

  drupal_set_message(t('Asset saved: <a href="@uri">%title</a>', array('@uri' => url($growroom_asset_uri['path']), '%title' => entity_label('growroom_asset', $growroom_asset))));
}

/**
 * Delete confirmation form.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 * @param GrowroomAsset $growroom_asset
 *   The growroom asset entity.
 *
 * @return array
 *   Returns a form array.
 */
function growroom_asset_delete_form(array $form, array &$form_state, GrowroomAsset $growroom_asset) {
  $form['growroom_asset'] = array(
    '#type' => 'value',
    '#value' => $growroom_asset,
  );
  // Always provide entity id in the same form key as in the entity edit form.
  $form['growroom_asset_type_id'] = array(
    '#type' => 'value',
    '#value' => entity_id('growroom_asset', $growroom_asset),
  );
  $growroom_asset_uri = entity_uri('growroom_asset', $growroom_asset);
  return confirm_form($form,
    t('Are you sure you want to delete %title?', array('%title' => entity_label('growroom_asset', $growroom_asset))),
    $growroom_asset_uri['path'],
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Delete form submit handler.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 */
function growroom_asset_delete_form_submit(array $form, array &$form_state) {
  $growroom_asset = $form_state['values']['growroom_asset'];
  growroom_asset_delete($growroom_asset);

  drupal_set_message(t('%title was deleted.', array('%title' => entity_label('growroom_asset', $growroom_asset))));

  $form_state['redirect'] = '<front>';
}
