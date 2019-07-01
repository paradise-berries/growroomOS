<?php
/**
 * Growroom Area hooks implemented by the Growroom Group module.
 */

/**
 * Implements hook_growroom_area_link_alter().
 */
function growroom_group_growroom_area_link_alter(&$link, $entity_info) {

  // We are only altering the link for group assets. Otherwise, bail.
  if (!($entity_info['entity_type'] == 'growroom_asset' && $entity_info['bundle'] == 'group')) {
    return;
  }

  // If there aren't any entity IDs, bail.
  if (empty($entity_info['entity_ids'])) {
    return;
  }

  // Load each of the groups.
  $groups = array();
  foreach ($entity_info['entity_ids'] as $id) {
    $group = growroom_asset_load($id);
    if (!empty($group)) {
      $groups[] = $group;
    }
  }

  // Recursively count all group members.
  $member_count = 0;
  foreach ($groups as $group) {
    $member_count += growroom_group_members_count_recursive($group);
  }

  // Alter the link to add the member count.
  if (!empty($member_count)) {
    $link['title'] .= ' (' . t('@count members', array('@count' => $member_count)) . ')';
  }
}

/**
 * Recursively count group members.
 *
 * @param GrowroomAsset $group
 *   The group asset to recurse into.
 *
 * @return int
 *   Returns the number of group members in the group, and in sub-groups.
 */
function growroom_group_members_count_recursive(GrowroomAsset $group) {

  // Start an empty counter.
  $count = 0;

  // Load the members of the group.
  $members = growroom_group_members($group);

  // If there are no members, return.
  if (empty($members)) {
    return $count;
  }

  // Count the members.
  $count += count($members);

  // Iterate through the members.
  foreach ($members as $member) {

    // If the member is a group, recurse into it and count it's members.
    if ($member->type == 'group') {
      $count += growroom_group_members_count_recursive($member);
    }
  }

  // Return the final count.
  return $count;
}
