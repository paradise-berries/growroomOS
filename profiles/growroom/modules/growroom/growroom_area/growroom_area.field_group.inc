<?php
/**
 * @file
 * growroom_area.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function growroom_area_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_description|taxonomy_term|growroom_areas|form';
  $field_group->group_name = 'group_growroom_description';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'growroom_areas';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '3',
    'children' => array(
      0 => 'description',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Description',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-growroom-description field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_growroom_description|taxonomy_term|growroom_areas|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_files|taxonomy_term|growroom_areas|form';
  $field_group->group_name = 'group_growroom_files';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'growroom_areas';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'File attachments',
    'weight' => '4',
    'children' => array(
      0 => 'field_growroom_files',
      1 => 'field_growroom_images',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'File attachments',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-growroom-files field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_growroom_files|taxonomy_term|growroom_areas|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_general|taxonomy_term|growroom_areas|form';
  $field_group->group_name = 'group_growroom_general';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'growroom_areas';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General information',
    'weight' => '0',
    'children' => array(
      0 => 'field_growroom_area_type',
      1 => 'field_growroom_flags',
      2 => 'name',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-growroom-general field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_growroom_general|taxonomy_term|growroom_areas|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_growroom_geometry|taxonomy_term|growroom_areas|form';
  $field_group->group_name = 'group_growroom_geometry';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'growroom_areas';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Geometry',
    'weight' => '2',
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
        'description' => t('Use this field to define the geometry of this area on a map. Points, lines, circles, and polygons (free-form shapes) can be drawn using the controls below. To draw a polygon, add a point at each corner, and double-click on the last one to close the shape. For more information about mapping areas in growroomOS, see <a href="@area-doc-url">@area-doc-url</a>', array('@area-doc-url' => 'https://growroomos.org/guide/areas')),
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_growroom_geometry|taxonomy_term|growroom_areas|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Description');
  t('File attachments');
  t('General information');
  t('Geometry');

  return $field_groups;
}
