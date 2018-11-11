(function (Drupal) {
  Drupal.behaviors.cLogDebug = {
    attach: function (context, settings) {
      if (settings.cLog && typeof settings.cLog.add !== "undefined") {
        settings.cLog.add.forEach(function(element) {
          Drupal.cLog.add(element.type, element.message, element.severity);
        });
      }
    }
  };
})(Drupal);
