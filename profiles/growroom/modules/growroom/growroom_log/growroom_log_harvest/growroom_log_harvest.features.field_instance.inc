<?php
/**
 * @file
 * growroom_log_harvest.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function growroom_log_harvest_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'log-growroom_harvest-field_growroom_area'.
  $field_instances['log-growroom_harvest-field_growroom_area'] = array(
    'bundle' => 'growroom_harvest',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'What areas is this harvest taking place in?',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'log',
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
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'log-growroom_harvest-field_growroom_asset'.
  $field_instances['log-growroom_harvest-field_growroom_asset'] = array(
    'bundle' => 'growroom_harvest',
    'deleted' => 0,
    'description' => 'What assets do this harvest log pertain to?',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 2,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'log',
    'field_name' => 'field_growroom_asset',
    'label' => 'Assets',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference_view_widget',
      'settings' => array(
        'allow_duplicates' => 0,
        'close_modal' => 1,
        'pass_argument' => 1,
        'pass_arguments' => '',
        'rendered_entity' => 0,
        'view' => 'growroom_asset_entityreference_view|entityreference_view_widget',
        'view_mode' => 'full',
      ),
      'type' => 'entityreference_view_widget',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'log-growroom_harvest-field_growroom_files'.
  $field_instances['log-growroom_harvest-field_growroom_files'] = array(
    'bundle' => 'growroom_harvest',
    'default_value' => array(),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_table',
        'weight' => 11,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'log',
    'field_name' => 'field_growroom_files',
    'label' => 'Files',
    'required' => 0,
    'settings' => array(
      'description_field' => 1,
      'file_directory' => 'growroom/log/harvest',
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
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'log-growroom_harvest-field_growroom_flags'.
  $field_instances['log-growroom_harvest-field_growroom_flags'] = array(
    'bundle' => 'growroom_harvest',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add flags to this log to enable better sorting and filtering of records.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'log',
    'field_name' => 'field_growroom_flags',
    'label' => 'Flags',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'log-growroom_harvest-field_growroom_geofield'.
  $field_instances['log-growroom_harvest-field_growroom_geofield'] = array(
    'bundle' => 'growroom_harvest',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This field is optional. It allows you to store geospatial data along with this harvest.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'openlayers_geofield',
        'settings' => array(
          'data' => 'full',
          'map_layer_preset' => 'growroom_map_geofield_formatter:openlayers_geofield_layer_formatter',
        ),
        'type' => 'openlayers_geofield',
        'weight' => 12,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'log',
    'field_name' => 'field_growroom_geofield',
    'label' => 'Geometry',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'openlayers_geofield',
      'settings' => array(
        'allow_edit' => 1,
        'data_storage' => 'collection',
        'delta_handling' => 'default',
        'feature_types' => array(
          'path' => 'path',
          'point' => 'point',
          'polygon' => 'polygon',
        ),
        'geocoder_field' => 'field_growroom_files',
        'geocoder_handler' => 'kml',
        'handler_settings' => array(
          'google' => array(
            'all_results' => 0,
            'geometry_type' => 'point',
            'reject_results' => array(
              'APPROXIMATE' => 0,
              'GEOMETRIC_CENTER' => 0,
              'RANGE_INTERPOLATED' => 0,
              'ROOFTOP' => 0,
            ),
          ),
        ),
        'openlayers_map' => 'growroom_map_geofield',
        'showInputField' => 1,
        'use_geocoder' => 1,
      ),
      'type' => 'openlayers_geofield',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'log-growroom_harvest-field_growroom_images'.
  $field_instances['log-growroom_harvest-field_growroom_images'] = array(
    'bundle' => 'growroom_harvest',
    'default_value' => array(),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'colorbox',
        'settings' => array(
          'colorbox_caption' => 'auto',
          'colorbox_caption_custom' => '',
          'colorbox_gallery' => 'post',
          'colorbox_gallery_custom' => '',
          'colorbox_image_style' => '',
          'colorbox_multivalue_index' => NULL,
          'colorbox_node_style' => 'thumbnail',
          'colorbox_node_style_first' => 'large',
        ),
        'type' => 'colorbox',
        'weight' => 10,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'log',
    'field_name' => 'field_growroom_images',
    'label' => 'Photos',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'growroom/log/harvest',
      'file_extensions' => '',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'multiupload_imagefield_widget',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
      ),
      'type' => 'image_miw',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'log-growroom_harvest-field_growroom_inventory'.
  $field_instances['log-growroom_harvest-field_growroom_inventory'] = array(
    'bundle' => 'growroom_harvest',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Use this to set or adjust asset inventory levels along with this log.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'field_collection',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_fields',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'log',
    'field_name' => 'field_growroom_inventory',
    'label' => 'Inventory adjustments',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 21,
    ),
  );

  // Exported field_instance: 'log-growroom_harvest-field_growroom_log_category'.
  $field_instances['log-growroom_harvest-field_growroom_log_category'] = array(
    'bundle' => 'growroom_harvest',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Use this to organize your logs into categories for easier searching and filtering later.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_plain',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'log',
    'field_name' => 'field_growroom_log_category',
    'label' => 'Log category',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'log-growroom_harvest-field_growroom_log_owner'.
  $field_instances['log-growroom_harvest-field_growroom_log_owner'] = array(
    'bundle' => 'growroom_harvest',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Optionally assign this task to one or more people.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'log',
    'field_name' => 'field_growroom_log_owner',
    'label' => 'Assigned to',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'log-growroom_harvest-field_growroom_lot_number'.
  $field_instances['log-growroom_harvest-field_growroom_lot_number'] = array(
    'bundle' => 'growroom_harvest',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If this harvest is part of a batch or lot, enter the lot number here.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'log',
    'field_name' => 'field_growroom_lot_number',
    'label' => 'Harvest lot number',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'log-growroom_harvest-field_growroom_movement'.
  $field_instances['log-growroom_harvest-field_growroom_movement'] = array(
    'bundle' => 'growroom_harvest',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Use these fields to record a movement with this log entry. This will be used to define the location of any referenced assets. The current location of any asset is determined by the most recently completed movement log. Only the "to" field is required.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_collection',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_fields',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'log',
    'field_name' => 'field_growroom_movement',
    'label' => 'Movement',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'log-growroom_harvest-field_growroom_notes'.
  $field_instances['log-growroom_harvest-field_growroom_notes'] = array(
    'bundle' => 'growroom_harvest',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'log',
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
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'log-growroom_harvest-field_growroom_quantity'.
  $field_instances['log-growroom_harvest-field_growroom_quantity'] = array(
    'bundle' => 'growroom_harvest',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Describe the quantity of this harvest, using a value, unit, and measure. For example, if you harvested 100 pounds of potatoes, enter "100" in the Value field, "lbs" in the Units field, and "Weight" in the Measure field. As you type the unit, you will have the option of selecting from units that you\'ve entered in the past.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'field_collection',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_fields',
        'weight' => 5,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'log',
    'field_name' => 'field_growroom_quantity',
    'label' => 'Quantity',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add flags to this log to enable better sorting and filtering of records.');
  t('Areas');
  t('Assets');
  t('Assigned to');
  t('Describe the quantity of this harvest, using a value, unit, and measure. For example, if you harvested 100 pounds of potatoes, enter "100" in the Value field, "lbs" in the Units field, and "Weight" in the Measure field. As you type the unit, you will have the option of selecting from units that you\'ve entered in the past.');
  t('Files');
  t('Flags');
  t('Geometry');
  t('Harvest lot number');
  t('If this harvest is part of a batch or lot, enter the lot number here.');
  t('Inventory adjustments');
  t('Log category');
  t('Movement');
  t('Notes');
  t('Optionally assign this task to one or more people.');
  t('Photos');
  t('Quantity');
  t('This field is optional. It allows you to store geospatial data along with this harvest.');
  t('Use these fields to record a movement with this log entry. This will be used to define the location of any referenced assets. The current location of any asset is determined by the most recently completed movement log. Only the "to" field is required.');
  t('Use this to organize your logs into categories for easier searching and filtering later.');
  t('Use this to set or adjust asset inventory levels along with this log.');
  t('What areas is this harvest taking place in?');
  t('What assets do this harvest log pertain to?');

  return $field_instances;
}
