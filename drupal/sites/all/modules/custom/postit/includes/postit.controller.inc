<?php

class PostItController extends DrupalDefaultEntityController{

  public function save($postit) {
    drupal_write_record('postit', $postit);
    field_attach_insert('postit', $postit);
    module_invoke_all('entity_insert', 'postit', $postit);
    return $postit;
  }
}

