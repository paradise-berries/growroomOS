<?php
/**
 * @file
 * growroom_pest.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function growroom_pest_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'growroom_plan-pest-field_growroom_area'.
  $field_instances['growroom_plan-pest-field_growroom_area'] = array(
    'bundle' => 'pest',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'What areas are part of this plan?',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'growroom_plan',
    'field_name' => 'field_growroom_area',
    'label' => 'Areas',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'growroom_plan-pest-field_growroom_date_range'.
  $field_instances['growroom_plan-pest-field_growroom_date_range'] = array(
    'bundle' => 'pest',
    'deleted' => 0,
    'description' => 'Define the date range for this pest management plan.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'short',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => 0,
        ),
        'type' => 'date_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'growroom_plan',
    'field_name' => 'field_growroom_date_range',
    'label' => 'Date range',
    'required' => 1,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'growroom_plan-pest-field_growroom_files'.
  $field_instances['growroom_plan-pest-field_growroom_files'] = array(
    'bundle' => 'pest',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_table',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'growroom_plan',
    'field_name' => 'field_growroom_files',
    'label' => 'Files',
    'required' => 0,
    'settings' => array(
      'description_field' => 1,
      'file_directory' => 'growroom/plan/pest',
      'file_extensions' => '',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'multiupload_filefield_widget',
      'settings' => array(
        'progress_indicator' => 'bar',
      ),
      'type' => 'file_mfw',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'growroom_plan-pest-field_growroom_notes'.
  $field_instances['growroom_plan-pest-field_growroom_notes'] = array(
    'bundle' => 'pest',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'growroom_plan',
    'field_name' => 'field_growroom_notes',
    'label' => 'Notes',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'growroom_plan-pest-field_growroom_season'.
  $field_instances['growroom_plan-pest-field_growroom_season'] = array(
    'bundle' => 'pest',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Optionally link this plan to a season. You can manage these options in the <a href="/admin/structure/taxonomy/growroom_season">Seasons</a> vocabulary.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'growroom_plan',
    'field_name' => 'field_growroom_season',
    'label' => 'Season',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Areas');
  t('Date range');
  t('Define the date range for this pest management plan.');
  t('Files');
  t('Notes');
  t('Optionally link this plan to a season. You can manage these options in the <a href="/admin/structure/taxonomy/growroom_season">Seasons</a> vocabulary.');
  t('Season');
  t('What areas are part of this plan?');

  return $field_instances;
}
