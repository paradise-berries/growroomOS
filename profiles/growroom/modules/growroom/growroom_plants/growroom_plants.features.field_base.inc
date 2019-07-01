<?php
/**
 * @file
 * growroom_plants.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function growroom_plants_field_default_field_bases() {
  $field_bases = array();

 // Exported field_base: 'field_growroom_individual_cultivar'.
  $field_bases['field_growroom_individual_cultivar'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_growroom_individual_cultivar',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'growroom_individual_cultivars',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_growroom_individual_fertility'.
  $field_bases['field_growroom_individual_fertility'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_growroom_individual_fertility',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'Heirloom' => 'Heirloom',
        'Hybrid' => 'Hybrid',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

    // Exported field_base: 'field_growroom_individual_barcode'.
    $field_bases['field_growroom_individual_barcode'] = array(
      'active' => 1,
      'cardinality' => -1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_growroom_individual_barcode',
      'indexes' => array(
        'revision_id' => array(
          0 => 'revision_id',
        ),
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => 0,
      'module' => 'field_collection',
      'settings' => array(
        'hide_blank_items' => 1,
        'hide_initial_item' => FALSE,
        'path' => '',
      ),
      'translatable' => 0,
      'type' => 'field_collection',
    );
  
    // Exported field_base: 'field_growroom_individual_barcode_id'.
    $field_bases['field_growroom_individual_barcode_id'] = array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_growroom_individual_barcode_id',
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => 0,
      'type' => 'text',
    );
      
  // Exported field_base: 'field_growroom_individual_mother'.
  $field_bases['field_growroom_individual_mother'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_growroom_individual_mother',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'individual' => 'individual',
        ),
      ),
      'target_type' => 'growroom_asset',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

   // Exported field_base: 'field_growroom_individual_origin'.
  $field_bases['field_growroom_individual_origin'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_growroom_individual_origin',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'Clone' => 'Clone',
        'Seed' => 'Seed',
        'Tissue' => 'Tissue',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );
    
  // Exported field_base: 'field_growroom_source'.
  $field_bases['field_growroom_source'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_growroom_source',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
