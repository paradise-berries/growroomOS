<?php

/**
 * @file
 * Growroom Area Views data.
 */

/**
 * Implements hook_views_data_alter().
 */
function growroom_area_views_data_alter(&$data) {

  // Add a field for growroom area details.
  $data['taxonomy_term_data']['growroom_area_details'] = array(
    'field' => array(
      'title' => t('Area Details'),
      'help' => t('Details that are relevant to growroom areas.'),
      'handler' => 'growroom_area_handler_field_details',
    ),
  );

  // Add a field for growroom area links.
  $data['taxonomy_term_data']['growroom_area_links'] = array(
    'field' => array(
      'title' => t('Area Links'),
      'help' => t('Links that are relevant to growroom areas.'),
      'handler' => 'growroom_area_handler_field_links',
    ),
  );
}
