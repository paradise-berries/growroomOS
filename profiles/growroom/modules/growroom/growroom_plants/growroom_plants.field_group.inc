<?php
/**
 * @file
 * growroom_plants.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function growroom_plants_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_assignment|log|growroom_repop|form';
  $field_group->group_name = 'group_growroom_assignment';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_repop';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_identification';
  $field_group->data = array(
    'label' => 'Assignment',
    'weight' => '4',
    'children' => array(
      0 => 'field_growroom_log_owner',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Assignment',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-growroom-assignment field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_growroom_assignment|log|growroom_repop|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_assignment|log|growroom_treatment|form';
  $field_group->group_name = 'group_growroom_assignment';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_treatment';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_identification';
  $field_group->data = array(
    'label' => 'Assignment',
    'weight' => '5',
    'children' => array(
      0 => 'field_growroom_log_owner',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Assignment',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-growroom-assignment field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_growroom_assignment|log|growroom_treatment|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_category|log|growroom_repop|form';
  $field_group->group_name = 'group_growroom_category';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_repop';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_identification';
  $field_group->data = array(
    'label' => 'Category',
    'weight' => '3',
    'children' => array(
      0 => 'field_growroom_log_category',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Category',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-growroom-category field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_growroom_category|log|growroom_repop|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_category|log|growroom_treatment|form';
  $field_group->group_name = 'group_growroom_category';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_treatment';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_identification';
  $field_group->data = array(
    'label' => 'Category',
    'weight' => '4',
    'children' => array(
      0 => 'field_growroom_log_category',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Category',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-growroom-category field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_growroom_category|log|growroom_treatment|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_offspring|log|growroom_repop|form';
  $field_group->group_name = 'group_growroom_offspring';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_repop';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_tabs';
  $field_group->data = array(
    'label' => 'Offspring',
    'weight' => '6',
    'children' => array(
      0 => 'field_growroom_asset',
      1 => 'field_growroom_movement',
      2 => 'field_growroom_membership',
    ),
    'format_type' => 'field_group_easy_responsive_tabs_nav_item',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-growroom-offspring field-group-field_group_easy_responsive_tabs_nav_item',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_growroom_offspring|log|growroom_repop|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_files|growroom_asset|individual|form';
  $field_group->group_name = 'group_growroom_files';
  $field_group->entity_type = 'growroom_asset';
  $field_group->bundle = 'individual';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_tabs';
  $field_group->data = array(
    'label' => 'Files',
    'weight' => '4',
    'children' => array(
      0 => 'field_growroom_files',
      1 => 'field_growroom_images',
    ),
    'format_type' => 'field_group_easy_responsive_tabs_nav_item',
    'format_settings' => array(
      'label' => 'Files',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_growroom_files|growroom_asset|individual|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_files|log|growroom_repop|form';
  $field_group->group_name = 'group_growroom_files';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_repop';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_tabs';
  $field_group->data = array(
    'label' => 'Files',
    'weight' => '9',
    'children' => array(
      0 => 'field_growroom_files',
      1 => 'field_growroom_images',
    ),
    'format_type' => 'field_group_easy_responsive_tabs_nav_item',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-growroom-files field-group-field_group_easy_responsive_tabs_nav_item',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_growroom_files|log|growroom_repop|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_files|log|growroom_treatment|form';
  $field_group->group_name = 'group_growroom_files';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_treatment';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_tabs';
  $field_group->data = array(
    'label' => 'Files',
    'weight' => '5',
    'children' => array(
      0 => 'field_growroom_files',
      1 => 'field_growroom_images',
    ),
    'format_type' => 'field_group_easy_responsive_tabs_nav_item',
    'format_settings' => array(
      'label' => 'Files',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_growroom_files|log|growroom_treatment|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_identification|growroom_asset|individual|form';
  $field_group->group_name = 'group_growroom_identification';
  $field_group->entity_type = 'growroom_asset';
  $field_group->bundle = 'individual';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_tabs';
  $field_group->data = array(
    'label' => 'Identification',
    'weight' => '1',
    'children' => array(
      0 => 'field_growroom_individual_cultivar',
      1 => 'field_growroom_description',
      2 => 'field_growroom_flags',
      3 => 'name',
      4 => 'group_growroom_individual',
    ),
    'format_type' => 'field_group_easy_responsive_tabs_nav_item',
    'format_settings' => array(
      'label' => 'Identification',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_growroom_identification|growroom_asset|individual|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_identification|log|growroom_repop|form';
  $field_group->group_name = 'group_growroom_identification';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_repop';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_tabs';
  $field_group->data = array(
    'label' => 'Identification',
    'weight' => '4',
    'children' => array(
      0 => 'field_growroom_notes',
      1 => 'timestamp',
      2 => 'field_growroom_flags',
      3 => 'group_growroom_category',
      4 => 'group_growroom_assignment',
    ),
    'format_type' => 'field_group_easy_responsive_tabs_nav_item',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-growroom-identification field-group-field_group_easy_responsive_tabs_nav_item',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_growroom_identification|log|growroom_repop|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_identification|log|growroom_treatment|form';
  $field_group->group_name = 'group_growroom_identification';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_treatment';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_tabs';
  $field_group->data = array(
    'label' => 'Identification',
    'weight' => '1',
    'children' => array(
      0 => 'field_growroom_asset',
      1 => 'field_growroom_notes',
      2 => 'field_growroom_flags',
      3 => 'name',
      4 => 'timestamp',
      5 => 'group_growroom_assignment',
      6 => 'group_growroom_category',
    ),
    'format_type' => 'field_group_easy_responsive_tabs_nav_item',
    'format_settings' => array(
      'label' => 'Identification',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_growroom_identification|log|growroom_treatment|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_geometry|log|growroom_repop|form';
  $field_group->group_name = 'group_growroom_geometry';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_repop';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_location';
  $field_group->data = array(
    'label' => 'Geometry',
    'weight' => '21',
    'children' => array(
      0 => 'field_growroom_geofield',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Geometry',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-growroom-geometry field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_growroom_geometry|log|growroom_repop|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_id|growroom_asset|individual|form';
  $field_group->group_name = 'group_growroom_id';
  $field_group->entity_type = 'growroom_asset';
  $field_group->bundle = 'individual';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_tabs';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '2',
    'children' => array(
      0 => 'field_growroom_individual_name',
    ),
    'format_type' => 'field_group_easy_responsive_tabs_nav_item',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_growroom_id|growroom_asset|individual|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_individual|growroom_asset|individual|form';
  $field_group->group_name = 'group_growroom_individual';
  $field_group->entity_type = 'growroom_asset';
  $field_group->bundle = 'individual';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_identification';
  $field_group->data = array(
    'label' => 'Individual',
    'weight' => '4',
    'children' => array(
      0 => 'field_growroom_date',
      1 => 'field_growroom_individual_cultivar', 
      2 => 'field_growroom_individual_alias', 
      3 => 'field_growroom_individual_origin', 
      4 => 'field_growroom_individual_fertility', 
      5 => 'field_growroom_source', 
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Individual',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-growroom-individual field-group-fieldset',
        'description' => 'If this record is for an individual, these fields can be used to provide more information. If this record is representing multiple individuals, you may leave these blank, and define the individual head count using the "Inventory" field below.',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_growroom_individual|growroom_asset|individual|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_inventory|log|growroom_repop|form';
  $field_group->group_name = 'group_growroom_inventory';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_repop';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_tabs';
  $field_group->data = array(
    'label' => 'Inventory',
    'weight' => '8',
    'children' => array(
      0 => 'field_growroom_inventory',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-growroom-inventory field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_growroom_inventory|log|growroom_repop|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_inventory|log|growroom_treatment|form';
  $field_group->group_name = 'group_growroom_inventory';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_treatment';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_tabs';
  $field_group->data = array(
    'label' => 'Inventory',
    'weight' => '4',
    'children' => array(
      0 => 'field_growroom_inventory',
    ),
    'format_type' => 'field_group_easy_responsive_tabs_nav_item',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-growroom-inventory field-group-field_group_easy_responsive_tabs_nav_item',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_growroom_inventory|log|growroom_treatment|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_lineage|growroom_asset|individual|form';
  $field_group->group_name = 'group_growroom_lineage';
  $field_group->entity_type = 'growroom_asset';
  $field_group->bundle = 'individual';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_tabs';
  $field_group->data = array(
    'label' => 'Lineage',
    'weight' => '3',
    'children' => array(
      0 => 'field_growroom_parent',
    ),
    'format_type' => 'field_group_easy_responsive_tabs_nav_item',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_growroom_lineage|growroom_asset|individual|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_location|log|growroom_repop|form';
  $field_group->group_name = 'group_growroom_location';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_repop';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_tabs';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '7',
    'children' => array(
      0 => 'field_growroom_area',
      1 => 'group_growroom_geometry',
    ),
    'format_type' => 'field_group_easy_responsive_tabs_nav_item',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-growroom-location field-group-field_group_easy_responsive_tabs_nav_item',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_growroom_location|log|growroom_repop|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_location|log|growroom_treatment|form';
  $field_group->group_name = 'group_growroom_location';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_treatment';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_tabs';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '2',
    'children' => array(
      0 => 'field_growroom_movement',
    ),
    'format_type' => 'field_group_easy_responsive_tabs_nav_item',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-growroom-location field-group-field_group_easy_responsive_tabs_nav_item',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_growroom_location|log|growroom_treatment|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_individual_mother|log|growroom_repop|form';
  $field_group->group_name = 'group_growroom_individual_mother';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_repop';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_tabs';
  $field_group->data = array(
    'label' => 'Mother',
    'weight' => '5',
    'children' => array(
      0 => 'field_growroom_individual_mother',
    ),
    'format_type' => 'field_group_easy_responsive_tabs_nav_item',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-growroom-mother field-group-field_group_easy_responsive_tabs_nav_item',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_growroom_individual_mother|log|growroom_repop|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_tabs|growroom_asset|individual|form';
  $field_group->group_name = 'group_growroom_tabs';
  $field_group->entity_type = 'growroom_asset';
  $field_group->bundle = 'individual';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_growroom_files',
      1 => 'group_growroom_identification',
      2 => 'group_growroom_id',
      3 => 'group_growroom_lineage',
    ),
    'format_type' => 'field_group_easy_responsive_tabs_nav',
    'format_settings' => array(
      'label' => 'Tabs',
      'instance_settings' => array(
        'type' => 'vertical',
        'width' => 'auto',
        'fit' => '1',
        'closed' => '0',
        'activetab_bg' => '',
        'inactive_bg' => '',
        'active_border_color' => '',
        'active_content_border_color' => '',
        'tabidentify' => '',
        'required_fields' => 1,
        'classes' => 'group-growroom-tabs field-group-field_group_easy_responsive_tabs_nav',
      ),
    ),
  );
  $field_groups['group_growroom_tabs|growroom_asset|individual|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_tabs|log|growroom_repop|form';
  $field_group->group_name = 'group_growroom_tabs';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_repop';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_growroom_identification',
      1 => 'group_growroom_files',
      2 => 'group_growroom_inventory',
      3 => 'group_growroom_offspring',
      4 => 'group_growroom_location',
      5 => 'group_growroom_individual_mother',
    ),
    'format_type' => 'field_group_easy_responsive_tabs_nav',
    'format_settings' => array(
      'label' => 'Tabs',
      'instance_settings' => array(
        'type' => 'vertical',
        'width' => 'auto',
        'fit' => '1',
        'closed' => '0',
        'activetab_bg' => '',
        'inactive_bg' => '',
        'active_border_color' => '',
        'active_content_border_color' => '',
        'tabidentify' => '',
        'required_fields' => 1,
        'classes' => 'group-growroom-tabs field-group-field_group_easy_responsive_tabs_nav',
      ),
    ),
  );
  $field_groups['group_growroom_tabs|log|growroom_repop|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_tabs|log|growroom_treatment|form';
  $field_group->group_name = 'group_growroom_tabs';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_treatment';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_growroom_files',
      1 => 'group_growroom_identification',
      2 => 'group_growroom_inventory',
      3 => 'group_growroom_location',
    ),
    'format_type' => 'field_group_easy_responsive_tabs_nav',
    'format_settings' => array(
      'label' => 'Tabs',
      'instance_settings' => array(
        'type' => 'vertical',
        'width' => 'auto',
        'fit' => '1',
        'closed' => '0',
        'activetab_bg' => '',
        'inactive_bg' => '',
        'active_border_color' => '',
        'active_content_border_color' => '',
        'tabidentify' => '',
        'required_fields' => 1,
        'classes' => 'group-growroom-tabs field-group-field_group_easy_responsive_tabs_nav',
      ),
    ),
  );
  $field_groups['group_growroom_tabs|log|growroom_treatment|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Assignment');
  t('Category');
  t('Offspring');
  t('Files');
  t('Identification');
  t('Geometry');
  t('Details');
  t('Individual');
  t('Inventory');
  t('Lineage');
  t('Location');
  t('Mother');
  t('Tabs');

  return $field_groups;
}
