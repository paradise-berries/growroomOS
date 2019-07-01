<?php
/**
 * @file
 * growroom_season.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function growroom_season_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
