<?php
/**
 * @file
 * A Views field handler for adding a print select option.
 */
class wfm_coupons_field_handler_print_select extends views_handler_field {
  function construct() {
    parent::construct();
  }

  function query() {
  }

  function render($args) {
    $index = $this->view->row_index;
    return $this->render_form_element($args->nid, $index);
  }

  function render_form_element($nid, $index) {
    $input = array(
      '#type' => 'checkbox',
      '#title_display' => 'after',
      '#id' => 'edit-print-select-' . $index,
      '#attributes' => array(
        'name' => 'print_select[' . $index . ']',
        'value' => $nid,
        'class' => array(
          'print-checkbox'
        ),
      ),
      '#title' => wfm_template_text_get_text('wfm_template_text_coupons_check_coupon'),
    );
    return render($input);
  }
}