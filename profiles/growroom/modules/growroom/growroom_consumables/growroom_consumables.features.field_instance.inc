<?php
/**
 * @file
 * growroom_consumables.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function growroom_consumables_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'growroom_asset-consumables-field_growroom_description'.
  $field_instances['growroom_asset-consumables-field_growroom_description'] = array(
    'bundle' => 'consumables',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'growroom_asset',
    'field_name' => 'field_growroom_description',
    'label' => 'Description',
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

  // Exported field_instance: 'growroom_asset-consumables-field_growroom_files'.
  $field_instances['growroom_asset-consumables-field_growroom_files'] = array(
    'bundle' => 'consumables',
    'default_value' => array(),
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
    'entity_type' => 'growroom_asset',
    'field_name' => 'field_growroom_files',
    'label' => 'Files',
    'required' => 0,
    'settings' => array(
      'description_field' => 1,
      'file_directory' => 'growroom/asset/consumables',
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
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'growroom_asset-consumables-field_growroom_flags'.
  $field_instances['growroom_asset-consumables-field_growroom_flags'] = array(
    'bundle' => 'consumables',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add flags to this asset to enable better sorting and filtering of records.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'growroom_asset',
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
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'growroom_asset-consumables-field_growroom_images'.
  $field_instances['growroom_asset-consumables-field_growroom_images'] = array(
    'bundle' => 'consumables',
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
        'weight' => 5,
      ),
    ),
    'entity_type' => 'growroom_asset',
    'field_name' => 'field_growroom_images',
    'label' => 'Photos',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'growroom/asset/consumables',
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
      'weight' => 8,
    ),
  );
  
      // Exported field_instance: 'growroom_asset-consumables-field_growroom_alias'.
  $field_instances['growroom_asset-consumables-field_growroom_alias'] = array(
    'bundle' => 'consumables',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'growroom_asset',
    'field_name' => 'field_growroom_alias',
    'label' => 'Alias',
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

  // Exported field_instance: 'growroom_asset-consumables-field_growroom_brand'.
  $field_instances['growroom_asset-consumables-field_growroom_brand'] = array(
    'bundle' => 'consumables',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'growroom_asset',
    'field_name' => 'field_growroom_brand',
    'label' => 'Brand',
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
  
   // Exported field_instance: 'growroom_asset-consumables-field_growroom_source'.
  $field_instances['growroom_asset-consumables-field_growroom_source'] = array(
    'bundle' => 'consumables',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'growroom_asset',
    'field_name' => 'field_growroom_source',
    'label' => 'Source',
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

  // Exported field_instance: 'growroom_asset-consumables-field_growroom_model'.
  $field_instances['growroom_asset-consumables-field_growroom_model'] = array(
    'bundle' => 'consumables',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'growroom_asset',
    'field_name' => 'field_growroom_model',
    'label' => 'Model',
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
      'weight' => 2,
    ),
  );
  
    // Exported field_instance: 'growroom_asset-consumables-field_growroom_specifications'
  $field_instances['growroom_asset-consumables-field_growroom_specifications'] = array(
    'bundle' => 'consumables',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'growroom_asset',
    'field_name' => 'field_growroom_specifications',
    'label' => 'Specifications',
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
      'weight' => 3,
    ),
  );
  

  // Exported field_instance: 'growroom_asset-consumables-field_growroom_purpose'
  $field_instances['growroom_asset-consumables-field_growroom_purpose'] = array(
    'bundle' => 'consumables',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'growroom_asset',
    'field_name' => 'field_growroom_purpose',
    'label' => 'Purpose',
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
      'weight' => 3,
    ),
  );
  
   // Exported field_instance: 'growroom_asset-consumables-field_growroom_method'
  $field_instances['growroom_asset-consumables-field_growroom_method'] = array(
    'bundle' => 'consumables',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'growroom_asset',
    'field_name' => 'field_growroom_method',
    'label' => 'Method',
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
      'weight' => 3,
    ),
  );

   // Exported field_instance: 'growroom_asset-consumables-field_growroom_storage'
  $field_instances['growroom_asset-consumables-field_growroom_storage'] = array(
    'bundle' => 'consumables',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'growroom_asset',
    'field_name' => 'field_growroom_storage',
    'label' => 'Storage',
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
      'weight' => 3,
    ),
  );
  
     // Exported field_instance: 'growroom_asset-consumables-field_growroom_shelf_life'
  $field_instances['growroom_asset-consumables-field_growroom_shelf_life'] = array(
    'bundle' => 'consumables',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'growroom_asset',
    'field_name' => 'field_growroom_shelf_life',
    'label' => 'Shelf Life',
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
      'weight' => 3,
    ),
  );
  
       // Exported field_instance: 'growroom_asset-consumables-field_growroom_warnings'
  $field_instances['growroom_asset-consumables-field_growroom_warnings'] = array(
    'bundle' => 'consumables',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'growroom_asset',
    'field_name' => 'field_growroom_warnings',
    'label' => 'Warnings',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'log-growroom_consumables-field_growroom_area'.
  $field_instances['log-growroom_consumables-field_growroom_area'] = array(
    'bundle' => 'growroom_consumables',
    'default_value' => array(),
    'deleted' => 0,
    'description' => 'What areas was this consumables used in?',
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
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'options_select',
      'weight' => 20,
    ),
  );
  
   // Exported field_instance: 'log-growroom_consumables-field_growroom_asset'.
  $field_instances['log-growroom_consumables-field_growroom_asset'] = array(
    'bundle' => 'growroom_consumables',
    'deleted' => 0,
    'description' => 'What consumables do this consumables log pertain to?',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => 1,
        ),
        'type' => 'entityreference_label',
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
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'log-growroom_consumables-field_growroom_files'.
  $field_instances['log-growroom_consumables-field_growroom_files'] = array(
    'bundle' => 'growroom_consumables',
    'default_value' => array(),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_table',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'log',
    'field_name' => 'field_growroom_files',
    'label' => 'Files',
    'required' => 0,
    'settings' => array(
      'description_field' => 1,
      'file_directory' => 'growroom/log/consumables',
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
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'log-growroom_consumables-field_growroom_flags'.
  $field_instances['log-growroom_consumables-field_growroom_flags'] = array(
    'bundle' => 'growroom_consumables',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add flags to this log to enable better sorting and filtering of records.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 5,
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
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'log-growroom_consumables-field_growroom_geofield'.
  $field_instances['log-growroom_consumables-field_growroom_geofield'] = array(
    'bundle' => 'growroom_consumables',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This field is optional. It allows you to store geospatial data along with this consumables record.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'openlayers_geofield',
        'settings' => array(
          'data' => 'full',
          'map_layer_preset' => 'growroom_map_geofield_formatter:openlayers_geofield_layer_formatter',
        ),
        'type' => 'openlayers_geofield',
        'weight' => 10,
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
            'biasing' => array(
              'bounds' => '',
              'components' => '',
              'region' => '',
            ),
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
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'log-growroom_consumables-field_growroom_images'.
  $field_instances['log-growroom_consumables-field_growroom_images'] = array(
    'bundle' => 'growroom_consumables',
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
        'weight' => 8,
      ),
    ),
    'entity_type' => 'log',
    'field_name' => 'field_growroom_images',
    'label' => 'Photos',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'growroom/log/consumables',
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
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'log-growroom_input-field_growroom_consumables_method'.
  $field_instances['log-growroom_input-field_growroom_consumables_method'] = array(
    'bundle' => 'growroom_consumables',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'How was this consumables applied?',
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
    'field_name' => 'field_growroom_consumables_method',
    'label' => 'Application method',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'log-growroom_input-field_growroom_consumables_purpose'.
  $field_instances['log-growroom_input-field_growroom_consumables_purpose'] = array(
    'bundle' => 'growroom_consumables',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'What was the purpose of this input?',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_growroom_consumables_purpose',
    'label' => 'Purpose',
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
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'log-growroom_consumables-field_growroom_inventory'.
  $field_instances['log-growroom_consumables-field_growroom_inventory'] = array(
    'bundle' => 'growroom_consumables',
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
        'weight' => 3,
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
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'log-growroom_consumables-field_growroom_log_category'.
  $field_instances['log-growroom_consumables-field_growroom_log_category'] = array(
    'bundle' => 'growroom_consumables',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Use this to organize your logs into categories for easier searching and filtering later.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 6,
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
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'log-growroom_consumables-field_growroom_log_owner'.
  $field_instances['log-growroom_consumables-field_growroom_log_owner'] = array(
    'bundle' => 'growroom_consumables',
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
        'weight' => 7,
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
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'log-growroom_consumables-field_growroom_movement'.
  $field_instances['log-growroom_consumables-field_growroom_movement'] = array(
    'bundle' => 'growroom_consumables',
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
        'weight' => 2,
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'log-growroom_consumables-field_growroom_notes'.
  $field_instances['log-growroom_consumables-field_growroom_notes'] = array(
    'bundle' => 'growroom_consumables',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'log-growroom_input-field_growroom_quantity'.
  $field_instances['log-growroom_input-field_growroom_quantity'] = array(
    'bundle' => 'growroom_input',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Describe the quantity of this input, using a value, unit, and measure. For example, if you used 10 gallons of liquid fertilizer, enter "10" in the Value field, and "gallons" in the Units field. As you type the unit, you will have the option of selecting from units that you\'ve entered in the past.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'field_collection',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_fields',
        'weight' => 1,
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
      'weight' => 1,
    ),
  );


  // Translatables
  // Included for use with string extractors like potx.
  t('Add flags to this asset to enable better sorting and filtering of records.');
  t('Add flags to this log to enable better sorting and filtering of records.');
  t('Application method');
  t('Areas');
  t('Assets');
  t('Assigned to');
  t('Description');
  t('Describe the quantity of this consumable used, using a value, unit, and measure.');
  t('Files');
  t('Flags');
  t('Geometry');
  t('Inventory adjustments');
  t('Log category');
  t('Supplier');
  t('Model');
  t('Storage');
  t('Movement');
  t('Notes');
  t('Optionally assign this task to one or more people.');
  t('Photos');
  t('Serial number');
  t('This field is optional. It allows you to store geospatial data along with this consumables record.');
  t('Use these fields to record a movement with this log entry. This will be used to define the location of any referenced assets. The current location of any asset is determined by the most recently completed movement log. Only the "to" field is required.');
  t('Use this to organize your logs into categories for easier searching and filtering later.');
  t('Use this to set or adjust asset inventory levels along with this log.');
  t('What areas did this consumables take place in?');
  t('What assets do this consumables log pertain to?');

  return $field_instances;
}