(function ($) {
  Drupal.behaviors.ajaxFormMsgs = {
    attach: function (context) {
      $(document).bind('clientsideValidationAddCustomRules', function(event){
        jQuery.validator.addMethod("ajaxFormMessage", function(value, element, param) {
          // Don't do anything if the value hasn't changed, return old result.
          if (typeof this.result != 'undefined' && this.oldvalue == value ) {
            // We don't have to check on typeof this.oldvalue != 'undefined'
            // because if this.result is defined, so is the old value.
            return this.result['result'];
          }
          // Save old value to prevent any action unless value changes.
          this.oldvalue = value;
          jQuery.ajax({
            'url': Drupal.settings.basePath + 'formmsgs/ajax/' + param['callback'],
            'type': 'POST',
            'data': {
              'value': value,
              'param': param
            },
            'dataType': 'json',
            'async': false,
            'success': function(res){
              result = res;
            }
          });
          // Weirdly, if we don't return a custom message, no message is displayed--
          // but if we do return a custom message, the default message is shown.
          if (result['result'] === false) {
            if (result['message'].length) {
              jQuery.extend(jQuery.validator.messages, {
                "ajaxFormMessage": result['message']
              });
            }
          }
          this.result = result;
          return result['result'];
        });

      });
    }
  }
})(jQuery);
