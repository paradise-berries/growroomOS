<?php
/**
 * @file
 * growroom_nutrients.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function growroom_nutrients_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_areas|log|growroom_mixing|form';
  $field_group->group_name = 'group_growroom_areas';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_mixing';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_location';
  $field_group->data = array(
    'label' => 'Areas',
    'weight' => '19',
    'children' => array(
      0 => 'field_growroom_area',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Areas',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-growroom-areas field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_growroom_areas|log|growroom_mixing|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_assets|log|growroom_mixing|form';
  $field_group->group_name = 'group_growroom_assets';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_mixing';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_tabs';
  $field_group->data = array(
    'label' => 'Assets',
    'weight' => '2',
    'children' => array(
      0 => 'field_growroom_asset',
      1 => 'field_growroom_movement',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Assets',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-growroom-assets field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_growroom_assets|log|growroom_mixing|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_assignment|log|growroom_mixing|form';
  $field_group->group_name = 'group_growroom_assignment';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_mixing';
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
  $field_groups['group_growroom_assignment|log|growroom_mixing|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_category|log|growroom_mixing|form';
  $field_group->group_name = 'group_growroom_category';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_mixing';
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
  $field_groups['group_growroom_category|log|growroom_mixing|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_files|growroom_asset|nutrients|form';
  $field_group->group_name = 'group_growroom_files';
  $field_group->entity_type = 'growroom_asset';
  $field_group->bundle = 'nutrients';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_tabs';
  $field_group->data = array(
    'label' => 'Files',
    'weight' => '2',
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
  $field_groups['group_growroom_files|growroom_asset|nutrients|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_files|log|growroom_mixing|form';
  $field_group->group_name = 'group_growroom_files';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_mixing';
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
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_growroom_files|log|growroom_mixing|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_identification|growroom_asset|nutrients|form';
  $field_group->group_name = 'group_growroom_identification';
  $field_group->entity_type = 'growroom_asset';
  $field_group->bundle = 'nutrients';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_tabs';
  $field_group->data = array(
    'label' => 'Identification',
    'weight' => '1',
    'children' => array(
      0 => 'field_growroom_description',
      1 => 'field_growroom_chemical',
      2 => 'field_growroom_alias',
      3 => 'field_growroom_brand',
      4 => 'field_growroom_source',
      5 => 'field_growroom_form',
      6 => 'field_growroom_specifications',
      7 => 'field_growroom_purpose',
      8 => 'field_growroom_method',
      9 => 'field_growroom_storage',
      10 => 'field_growroom_shelf_life',
      11 => 'field_growroom_warnings',
      12 => 'field_growroom_flags',
      13 => 'name',
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
  $field_groups['group_growroom_identification|growroom_asset|nutrients|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_identification|log|growroom_mixing|form';
  $field_group->group_name = 'group_growroom_identification';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_mixing';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_tabs';
  $field_group->data = array(
    'label' => 'Identification',
    'weight' => '1',
    'children' => array(
      0 => 'field_growroom_notes',
      1 => 'field_growroom_flags',
      2 => 'name',
      3 => 'timestamp',
      4 => 'group_growroom_category',
      5 => 'group_growroom_assignment',
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
  $field_groups['group_growroom_identification|log|growroom_mixing|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_geometry|log|growroom_mixing|form';
  $field_group->group_name = 'group_growroom_geometry';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_mixing';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_location';
  $field_group->data = array(
    'label' => 'Geometry',
    'weight' => '20',
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
  $field_groups['group_growroom_geometry|log|growroom_mixing|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_inventory|log|growroom_mixing|form';
  $field_group->group_name = 'group_growroom_inventory';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_mixing';
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
  $field_groups['group_growroom_inventory|log|growroom_mixing|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_location|log|growroom_mixing|form';
  $field_group->group_name = 'group_growroom_location';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_mixing';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_tabs';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '3',
    'children' => array(
      0 => 'group_growroom_geometry',
      1 => 'group_growroom_areas',
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
  $field_groups['group_growroom_location|log|growroom_mixing|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_tabs|growroom_asset|nutrients|form';
  $field_group->group_name = 'group_growroom_tabs';
  $field_group->entity_type = 'growroom_asset';
  $field_group->bundle = 'nutrients';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_growroom_files',
      1 => 'group_growroom_identification',
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
  $field_groups['group_growroom_tabs|growroom_asset|nutrients|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_tabs|log|growroom_mixing|form';
  $field_group->group_name = 'group_growroom_tabs';
  $field_group->entity_type = 'log';
  $field_group->bundle = 'growroom_mixing';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_growroom_assets',
      1 => 'group_growroom_files',
      2 => 'group_growroom_identification',
      3 => 'group_growroom_inventory',
      4 => 'group_growroom_location',
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
  $field_groups['group_growroom_tabs|log|growroom_mixing|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Areas');
  t('Assets');
  t('Assignment');
  t('Category');
  t('Files');
  t('Identification');
  t('Geometry');
  t('Inventory');
  t('Location');
  t('Tabs');

  return $field_groups;
}
