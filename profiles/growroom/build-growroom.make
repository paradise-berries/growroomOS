api = 2
core = 7.x

; -----------------------------------------------------------------------------
; Drupal core
; -----------------------------------------------------------------------------

includes[] = drupal-org-core.make

; -----------------------------------------------------------------------------
; growroomOS installation profile
; -----------------------------------------------------------------------------

projects[growroom][type] = profile
projects[growroom][version] = .01-beta
;projects[growroom][download][type] = git
;projects[growroom][download][url] = http://git.drupal.org/project/growroom.git
;projects[growroom][download][branch] = 7.x-0.01x
