/**
 * @file
 * Javascript file for coupons feature behavior.
 */

(function wfmCoupons($) {
  "use strict";

  var coupons = {

    /**
     * Add event listeners
     */
    addListeners: function() {
      // Select All functionality
      $('#edit-select-all-coupons').change(function() {
        if ($(this).prop('checked') == true) {
          $('.print-checkbox').prop('checked', true);
        }
        else {
          $('.print-checkbox').prop('checked', false);
        }
      });

      // GTM reporting user clicked on the sales flyer for the store
      $('.sales-flyer-pdf, .sales-pdf').click(function(event) {
        var pdfURL = $(this).attr('href');
        var fileName = pdfURL.split("/").pop();
        var fnArray = fileName.split("_");
        var tlc = fnArray[0];

        window.dataLayer.push({
          event: 'download-file',
          filetype: 'pdf',
          filename: fileName,
          storeid: tlc
        });
      });
    },

    /**
     * Initialization function
     */
    init: function() {
      coupons.addListeners();
    },

    /**
     * Set info based on selected store
     * @param storenid int
     *   Store node id. 
     */
    setSelectedStore: function(storenid) {
      if (typeof Drupal.WholeFoods.setStoreSelectStore == 'undefined') {
        jQuery('body').once('ss-attach', function () {
          jQuery('.store-select-form').WFMstoreSelect();
        });
        Drupal.WholeFoods.getStoreInfo(storenid, Drupal.WholeFoods.setStoreSelectStore);
      }
    },

    /**
     * Detemines if we're in wholefoods or wholefoods_mobile theme
     * @return string 
     */
    whichTheme: function() {
      if ($('html').hasClass('wholefoods-theme')) {
        return 'wholefoods';
      }
      else if ($('html').hasClass('wholefoods-mobile-theme')) {
        return 'wholefoods_mobile';
      }
    },
  };

  /**
   * Attach to Drupal.behaviors
   */
  Drupal.behaviors.wfm_coupons = {
    attach: function (context) {
      $('body', context).once('wfmCoupons', function() {
        coupons.init();
      });
    }
  };

})(jQuery);