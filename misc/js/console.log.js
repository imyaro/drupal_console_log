(function (Drupal) {
  Drupal.cLog = Drupal.cLog || {logs: []};

  Drupal.cLog.add = function(type, message, severity) {
    this.logs.push({'type': type, 'message': message, 'sevetity' : severity});

    var settings = Drupal.settings.cLog;

    var color = severity > 3 ? settings.priority.high : settings.priority.normal;
    var method = settings.method;

    console[method](
      "%c[" + type +"]", "color: " + color + "; font-weight:bold",
      message
    )
  };

})(Drupal);
