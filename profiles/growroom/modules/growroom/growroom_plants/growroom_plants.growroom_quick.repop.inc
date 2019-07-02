<?php
/**
 * @file
 * Growroom Plants repop quick form.
 */

/**
 * repop quick form.
 */
function growroom_plants_repop_form($form, &$form_state) {

  // Wrapper fieldset.
  $form['repop'] = array(
    '#type' => 'fieldset',
    '#title' => t('Record an individual repop'),
    '#description' => t('Use this form to record the repop of one or more individuals. A new repop log will be created, along with the new offspring individual records.'),
    '#tree' => TRUE,
  );

  // Date select (default to now).
  $form['repop']['timestamp'] = array(
    '#type' => 'date_select',
    '#title' => t('Date'),
    '#date_format' => 'm j m H:i',
    '#date_type' => DATE_FORMAT_UNIX,
    '#date_year_range' => '-10:+3',
    '#default_value' => REQUEST_TIME,
    '#required' => TRUE,
  );

  // Mother individual reference. Required because we need to be able to get the
  // cultivar from at least one of the parents.
  $form['repop']['mother'] = array(
    '#type' => 'textfield',
    '#title' => t('Mother'),
    '#description' => t('Select the mother individual. As you type, a dropdown of matching individual names will appear. Click on the one you want, and the field will be filled in with the name and asset ID (example: "DateName [id: 123]"). The "[id: X]" portion is required.'),
    '#autocomplete_path' => 'growroom_asset/autocomplete/individual',
    '#required' => TRUE,
  );

  // Father individual reference.
  $form['repop']['father'] = array(
    '#type' => 'textfield',
    '#title' => t('Father'),
    '#description' => t('Select the father individual (optional). See the mother field above for instructions.'),
    '#autocomplete_path' => 'growroom_asset/autocomplete/individual',
  );

  // Number of offspring.
  $form['repop']['offspring'] = array(
    '#type' => 'select',
    '#title' => t('How many offspring were born?'),
    '#options' => drupal_map_assoc(range(1, 15)),
    '#default_value' => 1,
    '#ajax' => array(
      'callback' => 'growroom_plants_repop_form_ajax',
      'wrapper' => 'growroom-plants-repop-offspring',
    ),
  );

  // Create a wrapper around all offspring fields, for AJAX replacement.
  $form['repop']['offspring'] = array(
    '#prefix' => '<div id="growroom-plants-repop-offspring">',
    '#suffix' => '</div>',
  );

  // Add fields for each offspring.
  $offspring = 1;
  if (!empty($form_state['values']['repop']['offspring'])) {
    $offspring = $form_state['values']['repop']['offspring'];
  }
  for ($i = 0; $i < $offspring; $i++) {

    // Fieldset for the offspring.
    $form['repop']['offspring'][$i] = array(
      '#type' => 'fieldset',
      '#title' => t('Offspring @number', array('@number' => $i + 1)),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

    // Individual name.
    $form['repop']['offspring'][$i]['name'] = array(
      '#type' => 'textfield',
      '#title' => t('Name'),
      '#description' => t('Give the individual a name (and/or barcode ID below). If the name is left blank, then it will be copied from the barcode ID.'),
      '#weight' => 0,
    );

    // Barcode ID.
    $form['repop']['offspring'][$i]['barcode_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Barcode ID'),
    '#weight' => 0,
    );
    
    // Origin of Offspring.
    $form['repop']['offspring'][$i]['origin'] = array(
      '#type' => 'radios',
      '#title' => t('Origin'),
      '#options' => array(
        'Clone' => t('Clone'),
        'Seed' => t('Seed'),
        'Cultured' => t('Cultured'),
      ),
      '#weight' => 9,
    );
    // Fertility of Offspring.
    $form['repop']['offspring'][$i]['fertility'] = array(
      '#type' => 'radios',
      '#title' => t('Fertility'),
      '#options' => array(
        'Hybrid' => t('Hybrid'),
        'Heirloom' => t('Heirloom'),
      ),
      '#weight' => 10,
    );
    
    // Individual description.
    $form['repop']['offspring'][$i]['description'] = array(
      '#type' => 'text_format',
      '#title' => t('Description'),
      '#format' => 'growroom_format',
      '#weight' => 30,
    );

    // Survived.
    $form['repop']['offspring'][$i]['survived'] = array(
      '#type' => 'checkbox',
      '#title' => t('Survived repop'),
      '#description' => t('Uncheck this if the offspring did not survive. The offspring individual record will still be created, but will be immediately archived.'),
      '#default_value' => TRUE,
      '#weight' => 40,
    );
  }

  // Repop notes.
  $form['repop']['notes'] = array(
    '#type' => 'text_format',
    '#title' => t('Repop notes'),
    '#format' => 'growroom_format',
  );

  // Submit button.
  $form['repop']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save repop records'),
  );

  // Return the form.
  return $form;
}

/**
 * Form ajax function for repop quick form.
 */
function growroom_plants_repop_form_ajax($form, &$form_state) {
  return $form['repop']['offspring'];
}

/**
 * Validate callback for repop quick form.
 */
function growroom_plants_repop_form_validate($form, &$form_state) {

  // Validate mother and father.
  $parents = array(
    'mother',
    'father',
  );
  foreach ($parents as $parent) {
    if (!empty($form_state['values']['repop'][$parent])) {

      // Extract asset ID.
      $id = 0;
      $matches = array();
      $result = preg_match('/\\[id: ([0-9]+)\\]$/', $form_state['values']['repop'][$parent], $matches);
      if (!empty($matches[$result])) {
        $id = $matches[$result];
      }

      // If an ID couldn't be extracted, throw an error.
      if (empty($id)) {
        form_set_error('repop][' . $parent, t('Could not load the @parent individual record. Make sure the individual asset ID is included. For example: "My individual [id: 123]"', array('@parent' => $parent)));
        continue;
      }

      // Load the asset.
      $asset = growroom_asset_load($id);

      // If the asset didn't load, throw an error.
      if (empty($asset)) {
        form_set_error('repop][' . $parent, t('Could not load the @parent individual record. Make sure the individual name and ID are correct.', array('@parent' => $parent)));
        continue;
      }

      // Save the asset to the form state.
      $form_state['storage'][$parent] = $asset;
    }
  }

  // If both a mother and a father are specified, make sure they're different.
  if (!empty($form_state['storage']['mother']) && !empty($form_state['storage']['father'])) {
    if ($form_state['storage']['mother']->id == $form_state['storage']['father']->id) {
      unset($form_state['storage']['father']);
      form_set_error('repop][father', t('The mother and father cannot be the same individual.'));
    }
  }

  // Iterate through the offspring.
  foreach ($form_state['values']['repop']['offspring'] as $i => $offspring) {

    // Make sure that either the name or barcode ID is filled in.
    if (empty($offspring['name']) && empty($offspring['barcode_id'])) {
      form_set_error('repop][offspring][' . $i . '][name', t('The offspring must have a name or cultivar.'));
    }
  }
}

/**
 * Submit callback for repop quick form.
 */
function growroom_individual_repop_form_submit($form, &$form_state) {

  // Get the repop timestamp.
  $timestamp = strtotime($form_state['values']['repop']['timestamp']);

  // Get the mother and father individuals, if they exists.
  $parents = array(
    'mother' => FALSE,
    'father' => FALSE,
  );
  if (!empty($form_state['storage']['mother'])) {
    $parents['mother'] = $form_state['storage']['mother'];
  }
  if (!empty($form_state['storage']['father'])) {
    $parents['father'] = $form_state['storage']['father'];
  }

  // Iterate through the offspring, and build an array of their asset records.
  $offspring = array();
  foreach ($form_state['values']['repop']['offspring'] as $offspring) {

    // If the name is not set, but barcode ID is, copy the barcode ID to the name.
    if (empty($offspring['name']) && !empty($offspring['barcode_id'])) {
      $offspring['name'] = $offspring['barcode_id'];
    }

    // Create a new individual asset.
    $values = array(
      'type' => 'individual',
      'name' => $offspring['name'],
      'created' => $timestamp,
    );
    $offspring_asset = entity_create('growroom_asset', $values);
    $offspring_wrapper = entity_metadata_wrapper('growroom_asset', $offspring_asset);

    // Set the individual's repop date to the date of the log.
    $offspring_wrapper->field_growroom_date->set($timestamp);

    // Set the individual's barcode ID, if available. Create a new barcode ID
    // field_collection entity attached to the individual.
    if (!empty($offspring['barcode_id'])) {
      $individual_barcode = entity_create('field_collection_item', array('field_name' => 'field_growroom_individual_barcode'));
      $individual_barcode->setHostEntity('growroom_asset', $offspring_asset);
      $individual_barcode_wrapper = entity_metadata_wrapper('field_collection_item', $individual_barcode);
      $individual_barcode_wrapper->field_growroom_individual_barcode->set($offspring['barcode_id']);
      $individual_barcode_wrapper->save();
    }

    // Set the individual's origin, if available.
    if (!empty($offspring['origin'])) {
      $offspring_wrapper->field_growroom_individual_origin->set($offspring['origin']);
    }

    // Set the individual's description, if available.
    if (!empty($offspring['description']['value'])) {
      $offspring_wrapper->field_growroom_description->set($offspring['description']);
    }

    // Iterate through the parents.
    foreach ($parents as $name => $parent) {

      // If an asset is not loaded, skip it.
      if (empty($parent)) {
        continue;
      }

      // Add them to the offspring's parents.
      $offspring_wrapper->field_growroom_parent[] = $parent->id;

      // Load metadata wrapper.
      $parent_wrapper = entity_metadata_wrapper('growroom_asset', $parent);

      // If this is the mother...
      if ($name == 'mother') {

        // Copy the cultivar to the offspring.
        $individual_cultivar = $parent_wrapper->field_growroom_individual_cultivar->value();
        $offspring_wrapper->field_growroom_individual_cultivar->set($individual_cultivar);

        // Copy the alias to the offspring.
        $individual_alias = $parent_wrapper->field_growroom_individual_alias->value();
        $offspring_wrapper->field_growroom_individual_alias->set($individual_alias);
      }
    }

    // If the offspring did not survive, then archive them.
    if (empty($offspring['survived'])) {
      $offspring_wrapper->archived->set($timestamp);
    }

    // Save the individual asset.
    $offspring_wrapper->save();

    // Add it to the array.
    $offspring[] = $offspring_asset;

    // Link the asset to this quick form.
    if (function_exists('growroom_quick_entity_link')) {
      growroom_quick_entity_link('growroom_plants_repop_form', 'growroom_asset', $offspring_asset);
    }

    // Set a message.
    $label = entity_label('growroom_asset', $offspring_asset);
    $uri = entity_uri('growroom_asset', $offspring_asset);
    drupal_set_message('Offspring individual created: ' . l($label, $uri['path']));

    // If the individual's weight was specified, create a weight measurement log.
    if (!empty($offspring['weight'])) {
      growroom_plants_weight_set($offspring_asset, $offspring['weight'], $offspring['units'], $timestamp);
    }
  }

  // Create a repop log. Leave the name blank so that it is auto-generated.
  $log_type = 'growroom_repop';
  $log_name = '';
  $log = growroom_log_create($log_type, $log_name, $timestamp, TRUE, $offspring);

  // Create an entity metadata wrapper for the log.
  $log_wrapper = entity_metadata_wrapper('log', $log);

  // Set the repop mother.
  $log_wrapper->field_growroom_individual_mother->set($parents['mother']->id);

  // Set the location (from the mother, if available).
  $movement_log = growroom_movement_asset_latest_movement($parents['mother']);
  if (!empty($movement_log)) {
    $movement_log_wrapper = entity_metadata_wrapper('log', $movement_log);
    $movement_field = entity_create('field_collection_item', array('field_name' => 'field_growroom_movement'));
    $movement_field->setHostEntity('log', $log);
    $movement_field_wrapper = entity_metadata_wrapper('field_collection_item', $movement_field);
    $movement_field_wrapper->field_growroom_move_to->set($movement_log_wrapper->field_growroom_movement->field_growroom_move_to->value());
    $movement_field_wrapper->field_growroom_geofield->set($movement_log_wrapper->field_growroom_movement->field_growroom_geofield->value());
    $movement_field_wrapper->save();
  }

  // Set the group membership (from the mother, if available).
  $membership_log = growroom_group_asset_latest_membership($parents['mother']);
  if (!empty($membership_log)) {
    $membership_log_wrapper = entity_metadata_wrapper('log', $membership_log);
    $membership_field = entity_create('field_collection_item', array('field_name' => 'field_growroom_membership'));
    $membership_field->setHostEntity('log', $log);
    $membership_field_wrapper = entity_metadata_wrapper('field_collection_item', $membership_field);
    $membership_field_wrapper->field_growroom_group->set($membership_log_wrapper->field_growroom_membership->field_growroom_group->value());
    $membership_field_wrapper->save();
  }

  // Set the repop log notes, if available.
  if (!empty($form_state['values']['repop']['notes']['value'])) {
    $log_wrapper->field_growroom_notes->set($form_state['values']['repop']['notes']);
  }

  // Save the log.
  $log_wrapper->save();

  // Link the log to the quick form.
  if (function_exists('growroom_quick_entity_link')) {
    growroom_quick_entity_link('growroom_plants_repop_form', 'log', $log);
  }

  // Set a message linking to the mother individual.
  $label = entity_label('growroom_asset', $parents['mother']);
  $uri = entity_uri('growroom_asset', $parents['mother']);
  drupal_set_message("View the mother's individual record: " . l($label, $uri['path']));

  // Add the offspring to $form_state['storage'] so that other submit functions
  // can work with them.
  $form_state['storage']['offspring'] = $offspring;
}
