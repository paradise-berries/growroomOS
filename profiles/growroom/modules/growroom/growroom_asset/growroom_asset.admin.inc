<?php

/**
 * @file
 * Growroom asset admin pages.
 */

/**
 * Generates the growroom asset type editing form.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 * @param string $growroom_asset_type
 *   The growroom asset type.
 * @param string $op
 *   The operation being performed.
 *
 * @return array
 *   Returns a form array.
 */
function growroom_asset_type_form(array $form, array &$form_state, $growroom_asset_type, $op = 'edit') {

  if ($op == 'clone') {
    $growroom_asset_type->label .= ' (cloned)';
    $growroom_asset_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $growroom_asset_type->label,
    '#description' => t('The human-readable name of this asset type.'),
    '#required' => TRUE,
    '#size' => 30,
  );

  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => !empty($growroom_asset_type->type) ? $growroom_asset_type->type : '',
    '#maxlength' => 32,
    '#disabled' => $growroom_asset_type->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'growroom_asset_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this asset type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save asset type'),
    '#weight' => 40,
  );

  if (!$growroom_asset_type->isLocked() && $op != 'add' && $op != 'clone') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete asset type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('growroom_asset_type_form_submit_delete'),
    );
  }
  return $form;
}

/**
 * Submit handler for creating/editing asset types.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 */
function growroom_asset_type_form_submit(array &$form, array &$form_state) {
  $growroom_asset_type = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and go back.
  growroom_asset_type_save($growroom_asset_type);

  // Redirect user back to list of asset types.
  $form_state['redirect'] = 'admin/config/growroom/asset-types';
}

/**
 * Submit handler for deleting asset types.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 */
function growroom_asset_type_form_submit_delete(array &$form, array &$form_state) {
  $form_state['redirect'] = 'admin/config/growroom/asset-types/' . $form_state['growroom_asset_type']->type . '/delete';
}

/**
 * Asset type delete form.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 * @param string $growroom_asset_type
 *   The growroom asset type.
 *
 * @return array
 *   Returns a form array.
 */
function growroom_asset_type_form_delete_confirm(array $form, array &$form_state, $growroom_asset_type) {
  $form['growroom_asset_type'] = array(
    '#type' => 'value',
    '#value' => $growroom_asset_type,
  );
  // Always provide entity id in the same form key as in the entity edit form.
  $form['growroom_asset_type_id'] = array(
    '#type' => 'value',
    '#value' => entity_id('growroom_asset_type', $growroom_asset_type),
  );
  return confirm_form($form,
    t('Are you sure you want to delete asset type %title?', array('%title' => entity_label('growroom_asset_type', $growroom_asset_type))),
    'growroom/asset/' . entity_id('growroom_asset_type', $growroom_asset_type),
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Asset type delete form submit handler.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 */
function growroom_asset_type_form_delete_confirm_submit(array $form, array &$form_state) {
  $growroom_asset_type = $form_state['values']['growroom_asset_type'];
  growroom_asset_type_delete($growroom_asset_type);

  watchdog('growroom_asset', '@type: deleted %title.', array('@type' => $growroom_asset_type->type, '%title' => $growroom_asset_type->label));
  drupal_set_message(t('@type %title has been deleted.', array('@type' => $growroom_asset_type->type, '%title' => $growroom_asset_type->label)));

  $form_state['redirect'] = 'admin/config/growroom/asset-types';
}
