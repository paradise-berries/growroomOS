<?php
/**
 * @file
 * Growroom plan consideration constraints.
 */

/**
 * Implements hook_growroom_constraint().
 */
function growroom_plan_consideration_growroom_constraint($type, $bundle, $id) {

  // Check to see if this entity is referenced in the
  // {growroom_plan_consideration_entity} table.
  $exists = db_query('SELECT COUNT(*) FROM {growroom_plan_consideration_entity} WHERE entity_type = :entity_type AND entity_id = :entity_id', array(':entity_type' => $type, ':entity_id' => $id))->fetchField();
  if (!empty($exists)) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}
