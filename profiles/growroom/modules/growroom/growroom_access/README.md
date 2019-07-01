GROWROOM ACCESS
===========

Provides mechanisms for managing growroomOS user access permissions.

Three hooks are provided (see example usage in growroom_access.api.php):

* hook_growroom_access_roles() - for defining growroom roles
* hook_growroom_access_perms() - for defining growroom permissions
* hook_growroom_access_perms_alter() - for altering role permissions defined by other modules

Three roles are provided via hook_growroom_access_roles():
* Growroom Administrator
* Growroom Manager
* Growroom Worker
* Growroom Viewer

Most growroomOS modules implement hook_growroom_access_perms() to add their necessary
permissions to each of the three roles above. But you can also write a custom
module that implements this hook to do the same thing... if you want to craft
your own permissions. Or, you can use hook_growroom_access_perms_alter() to alter
the list of permissions defined by others.

The nice thing about this approach is we can include it in the growroomOS
distribution (http://drupal.org/project/growroom), but if other people want to use
a growroom_* module individually, and want to define their own permissions, they
can do that without a dependency on growroom_access. So it's the best of all worlds,
I think.

The only catch (right now), is that the permissions are very strictly enforced.
If you try to disable certain permissions in the Drupal UI, they will be
immediately reset to those defined by modules that implement
hook_growroom_access_perms(). This is because the module is not super complicated
... it just tries to determine which permissions the role DOES have, and
compares it to a list of permissions it SHOULD have... then it adds/removes
permissions to sync them up. If this is a problem for someone, they have two
choices: don't use the Growroom Access module, and do it yourself... or implement
hook_growroom_access_perms_alter() to make changes to the permissions available
to each role.

DEPENDENCIES
------------

**Requires Drupal core patch!**

Note that this module depends on a patch to Drupal core that ensures vocabulary
names are used in the naming of permissions, rather than vocabulary IDs (which
can vary from site to site).

Here is the patch: http://www.drupal.org/files/issues/995156-5_portable_taxonomy_permissions_0.patch

And the related issue thread: http://drupal.org/node/995156

This patch is already included in the growroomOS distribution.
