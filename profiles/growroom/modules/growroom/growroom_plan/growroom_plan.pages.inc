<?php

/**
 * @file
 * Growroom plan pages.
 */

/**
 * Plan view callback.
 *
 * @param GrowroomPlan $growroom_plan
 *   The growroom plan entity.
 *
 * @return array
 *   Returns the entity render array.
 */
function growroom_plan_view(GrowroomPlan $growroom_plan) {

  // Set the page title.
  drupal_set_title(entity_label('growroom_plan', $growroom_plan));

  // Build the plan's render array.
  $build = entity_view('growroom_plan', array(entity_id('growroom_plan', $growroom_plan) => $growroom_plan), 'full');

  // Return the render array.
  return $build;
}

/**
 * Page to select plan type to add new plan.
 */
function growroom_plan_add_types_page() {
  $items = array();
  foreach (growroom_plan_types() as $growroom_plan_type_key => $growroom_plan_type) {
    if (growroom_plan_access('create', $growroom_plan_type)) {
      $items[] = l(entity_label('growroom_plan_type', $growroom_plan_type), 'growroom/plan/add/' . $growroom_plan_type_key);
    }
  }
  return array(
    'list' => array(
      '#theme' => 'item_list',
      '#items' => $items,
      '#title' => t('Select a type of plan to create.'),
    ),
  );
}

/**
 * Add new plan page callback.
 *
 * @param string $type
 *   The growroom plan type.
 *
 * @return array
 *   Returns a form array.
 */
function growroom_plan_add($type) {
  $growroom_plan_type = growroom_plan_types($type);

  $growroom_plan = entity_create('growroom_plan', array('type' => $type));
  drupal_set_title(t('Add @name', array('@name' => entity_label('growroom_plan_type', $growroom_plan_type))));

  $output = drupal_get_form('growroom_plan_form', $growroom_plan);

  return $output;
}

/**
 * Plan form.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 * @param GrowroomPlan $growroom_plan
 *   The growroom plan entity.
 *
 * @return array
 *   Returns a form array.
 */
function growroom_plan_form(array $form, array &$form_state, GrowroomPlan $growroom_plan) {

  $form['growroom_plan'] = array(
    '#type' => 'value',
    '#value' => $growroom_plan,
  );

  // Load the plan type.
  $growroom_plan_type = growroom_plan_type_load($growroom_plan->type);

  // Plan name.
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('Give this %type a name.', array('%type' => $growroom_plan_type->label)),
    '#default_value' => $growroom_plan->name,
    '#required' => TRUE,
    '#weight' => -100,
  );

  // Additional settings (vertical tabs at the bottom of the form).
  $form['additional_settings'] = array(
    '#type' => 'vertical_tabs',
    '#weight' => 99,
  );

  // Plan active/inactive (new plans are active by default).
  if (empty($growroom_plan->id)) {
    $growroom_plan->active = TRUE;
  }
  $form['plan_status'] = array(
    '#type' => 'fieldset',
    '#title' => t('Plan status'),
    '#description' => t('Mark this plan as active/inactive. Inactive plans will not show in most lists, but will be visible in archives.'),
    '#collapsible' => TRUE,
    '#group' => 'additional_settings',
  );
  $form['plan_status']['active'] = array(
    '#type' => 'checkbox',
    '#title' => t('Active'),
    '#default_value' => $growroom_plan->active,
  );

  // Plan user id.
  $form['uid'] = array(
    '#type' => 'value',
    '#value' => $growroom_plan->uid,
  );

  field_attach_form('growroom_plan', $growroom_plan, $form, $form_state);

  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions'] = array(
    '#weight' => 100,
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#submit' => $submit + array('growroom_plan_form_submit'),
  );

  // Show Delete button if allowed.
  $growroom_plan_id = entity_id('growroom_plan', $growroom_plan);
  if (!empty($growroom_plan_id) && growroom_plan_access('delete', $growroom_plan)) {

    // Get the destination query parameter. If it is the current path, change
    // to <front> (because the current path won't exist once the plan is
    // deleted).
    $destination = drupal_get_destination();
    if ($destination['destination'] == current_path()) {
      $destination['destination'] = '<front>';
    }
    $form['actions']['delete'] = array(
      '#type' => 'markup',
      '#markup' => l(t('Delete'), 'growroom/plan/' . $growroom_plan_id . '/delete', array('query' => $destination)),
    );
  }

  return $form;
}

/**
 * Plan validate handler.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 */
function growroom_plan_form_validate(array $form, array &$form_state) {

}

/**
 * Plan submit handler.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 */
function growroom_plan_form_submit(array $form, array &$form_state) {
  $growroom_plan = $form_state['values']['growroom_plan'];

  entity_form_submit_build_entity('growroom_plan', $growroom_plan, $form, $form_state);

  growroom_plan_save($growroom_plan);

  $growroom_plan_uri = entity_uri('growroom_plan', $growroom_plan);

  $form_state['redirect'] = $growroom_plan_uri['path'];

  drupal_set_message(t('Plan saved: <a href="@uri">%title</a>', array('@uri' => url($growroom_plan_uri['path']), '%title' => entity_label('growroom_plan', $growroom_plan))));
}

/**
 * Delete confirmation form.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 * @param GrowroomPlan $growroom_plan
 *   The growroom plan entity.
 *
 * @return array
 *   Returns a form array.
 */
function growroom_plan_delete_form(array $form, array &$form_state, GrowroomPlan $growroom_plan) {
  $form['growroom_plan'] = array(
    '#type' => 'value',
    '#value' => $growroom_plan,
  );
  // Always provide entity id in the same form key as in the entity edit form.
  $form['growroom_plan_type_id'] = array(
    '#type' => 'value',
    '#value' => entity_id('growroom_plan', $growroom_plan),
  );
  $growroom_plan_uri = entity_uri('growroom_plan', $growroom_plan);
  return confirm_form($form,
    t('Are you sure you want to delete %title?', array('%title' => entity_label('growroom_plan', $growroom_plan))),
    $growroom_plan_uri['path'],
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
function growroom_plan_delete_form_submit(array $form, array &$form_state) {
  $growroom_plan = $form_state['values']['growroom_plan'];
  growroom_plan_delete($growroom_plan);

  drupal_set_message(t('%title was deleted.', array('%title' => entity_label('growroom_plan', $growroom_plan))));

  $form_state['redirect'] = '<front>';
}
