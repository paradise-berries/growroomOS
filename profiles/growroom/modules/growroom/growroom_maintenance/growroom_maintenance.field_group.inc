<?php
/**
 * @file
 * growroom_maintenance.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function growroom_maintenance_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_areas|growroom_plan|maintenance|form';
  $field_group->group_name = 'group_growroom_areas';
  $field_group->entity_type = 'growroom_plan';
  $field_group->bundle = 'maintenance';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_tabs';
  $field_group->data = array(
    'label' => 'Areas',
    'weight' => '5',
    'children' => array(
      0 => 'field_growroom_area',
    ),
    'format_type' => 'field_group_easy_responsive_tabs_nav_item',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-growroom-areas field-group-field_group_easy_responsive_tabs_nav_item',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_growroom_areas|growroom_plan|maintenance|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_files|growroom_plan|maintenance|form';
  $field_group->group_name = 'group_growroom_files';
  $field_group->entity_type = 'growroom_plan';
  $field_group->bundle = 'maintenance';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_tabs';
  $field_group->data = array(
    'label' => 'Files',
    'weight' => '7',
    'children' => array(
      0 => 'field_growroom_files',
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
  $field_groups['group_growroom_files|growroom_plan|maintenance|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_general|growroom_plan|maintenance|form';
  $field_group->group_name = 'group_growroom_general';
  $field_group->entity_type = 'growroom_plan';
  $field_group->bundle = 'maintenance';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_growroom_tabs';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '4',
    'children' => array(
      0 => 'field_growroom_date_range',
      1 => 'field_growroom_season',
      2 => 'field_growroom_notes',
      3 => 'name',
    ),
    'format_type' => 'field_group_easy_responsive_tabs_nav_item',
    'format_settings' => array(
      'label' => 'General',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-growroom-general field-group-field_group_easy_responsive_tabs_nav_item',
      ),
    ),
  );
  $field_groups['group_growroom_general|growroom_plan|maintenance|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_tabs|growroom_plan|maintenance|form';
  $field_group->group_name = 'group_growroom_tabs';
  $field_group->entity_type = 'growroom_plan';
  $field_group->bundle = 'maintenance';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_growroom_general',
      1 => 'group_growroom_files',
      2 => 'group_growroom_areas',
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
  $field_groups['group_growroom_tabs|growroom_plan|maintenance|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Areas');
  t('Files');
  t('General');
  t('Tabs');

  return $field_groups;
}
