<?php
/**
 * @file
 * growroom_quantity.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function growroom_quantity_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
