(function (Drupal) {

  Drupal.behaviors.cLogDebug = {
    attach: function (context, settings) {
      if (settings.cLog && typeof settings.cLog.debug !== "undefined") {
        settings.cLog.debug.forEach(function(element) {
          Drupal.cLog.debug(element.type, element.message, element.severity);
        });
      }
    }
  };

})(Drupal);
