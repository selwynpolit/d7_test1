<?php
/**
 * Implements hook_drush_command().
 */
function videodedupe_drush_command() {

  $items['video-dedupe-command'] = array(
    'description' => 'Remove duplicate video nodes.',
    'aliases' => array('vdd'),
    'callback' => '_videodedupe_delete',
  );

  return $items;
}


/**
 * Callback for Drush video de-dupe command.
 */
function _videodedupe_delete() {
  videodedupe_delete('article');
}