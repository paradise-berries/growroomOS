#!/bin/bash
set -e

# Function for archiving the sites folder.
archive_sites () {

  # If the sites folder exists, preserve it by temporarily archiving it.
  if [ -e /var/www/html/sites ]; then
    echo >&2 "Existing sites folder detected. Archiving temporarily..."
    tar -czf /var/www/html/sites.tar.gz /var/www/html/sites
  fi
}

# Function for restoring the sites folder.
restore_sites () {

  # Restore the sites folder.
  if [ -e /var/www/html/sites.tar.gz ]; then
    echo >&2 "Restoring sites directory..."
    rm -r /var/www/html/sites \
    && tar -xzf /var/www/html/sites.tar.gz -C /var/www/html/ --strip-components=3 \
    && rm /var/www/html/sites.tar.gz
  fi

  # Change ownership of the sites folder.
  chown -R www-data:www-data /var/www/html/sites
}

# Function for deleting the growroomOS codebase.
delete_growroomos () {

  # Remove the existing growroomOS codebase, if it exists.
  # Exclude sites.tar.gz.
  if [ -e /var/www/html/index.php ]; then
    echo >&2 "Removing existing growroomOS codebase..."
    find /var/www/html ! -name 'sites.tar.gz' -mindepth 1 -delete
  fi
}

# Function for downloading and unpacking a growroomOS release.
build_growroomos_release () {

  # Download and unpack growroomOS release.
  echo >&2 "Downloading growroomOS $GROWROOMOS_VERSION..."
  curl -SL "http://ftp.drupal.org/files/projects/growroom-${GROWROOMOS_VERSION}-core.tar.gz" -o /usr/src/growroom-${GROWROOMOS_VERSION}-core.tar.gz
  echo >&2 "Unpacking growroomOS $GROWROOMOS_VERSION..."
  tar -xvzf /usr/src/growroom-${GROWROOMOS_VERSION}-core.tar.gz -C /var/www/html/ --strip-components=1
}

# Function for building a dev branch of growroomOS.
build_growroomos_dev () {

  # Clone the growroomOS installation profile, if it doesn't already exist.
  if ! [ -e /var/growroomOS/build-growroom.make ]; then
    git clone --branch $GROWROOMOS_DEV_BRANCH https://git.drupal.org/project/growroom.git /var/growroomOS

  # Update it if it does exist.
  else
    git -C /var/growroomOS pull origin $GROWROOMOS_DEV_BRANCH
  fi

  # Build growroomOS with Drush. Use the --working-copy flag to keep .git folders.
  drush make --working-copy --no-gitinfofile /var/growroomOS/build-growroom.make /tmp/growroomOS \
  && cp -r /tmp/growroomOS/. /var/www/html \
  && rm -r /tmp/growroomOS
}

# Function for building growroomOS.
build_growroomos () {

  # If a development environment is desired, build from dev branch. Otherwise,
  # build from official packaged release.
  if $GROWROOMOS_DEV; then
    build_growroomos_dev
  else
    build_growroomos_release
  fi
}

# Function for determining whether a rebuild is required.
rebuild_required () {

  # If growroom.info doesn't exist, a rebuild is required.
  if ! [ -e /var/www/html/profiles/growroom/growroom.info ]; then
    echo >&2 "growroomOS not detected. Building..."
    return 0
  fi

  # Get the current version of growroomOS from the installation profile info file.
  CURRENT_VERSION="$(grep 'version' profiles/growroom/growroom.info | sed 's/version = .\(.*\)./\1/')"

  # If this is not a development build, and the current version does not match
  # the desired version, then rebuild.
  if ! $GROWROOMOS_DEV && [ "$CURRENT_VERSION" != "$GROWROOMOS_VERSION" ]; then
    echo >&2 "growroomOS $CURRENT_VERSION was detected. Replacing with $GROWROOMOS_VERSION..."
    return 0
  fi

  echo >&2 "An existing growroomOS codebase was detected."
  echo >&2 "To force a rebuild, delete profiles/growroom/growroom.info and restart the container."
  return 1
}

# Rebuild growroomOS, if necessary.
if rebuild_required; then

  # Archive the sites folder and delete the growroomOS codebase.
  archive_sites
  delete_growroomos

  # Build growroomOS.
  build_growroomos

  # Restore the sites folder.
  restore_sites
fi

# Execute the arguments passed into this script.
echo "Attempting: $@"
exec "$@"
