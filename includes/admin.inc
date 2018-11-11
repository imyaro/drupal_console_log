<?php
/**
 * @file
 * File contains form with the console log module settings.
 */

/**
 * Settings form for the console log module.
 */
function console_log_settings_form($form, $form_state) {
  $form['console_log_is_active'] = [
    '#type' => 'checkbox',
    '#title' => t('Console log module is active (For any user)'),
    '#description' => t('This option turns on module for <b>ALL USERS</b> independent from the permissions given inside the Drupal permissions. Please do not enable it on production.'),
    '#default_value' => variable_get('console_log_is_active'),
  ];
  $form['console_log_is_active_by_permission'] = [
    '#type' => 'checkbox',
    '#title' => t('Console log module is active (By permission)'),
    '#default_value' => variable_get('console_log_is_active_by_permission'),
  ];

  $form['console_log_options'] = [
    '#type' => 'fieldset',
    '#tree' => TRUE,
    '#states' => [
      'visible' => [
        // One of the options must be active to show others.
        [':input[name="console_log_is_active"]' => ['checked' => TRUE]],
        'OR',
        [':input[name="console_log_is_active_by_permission"]' => ['checked' => TRUE]],
      ],
    ],
  ];

  $options = console_log_get_options();

  $form['console_log_options']['priority'] = [
    '#title' => t('Priority colors'),
    '#description' => t('Please use HEX color codes'),
    '#type' => 'fieldset',
  ];

  $form['console_log_options']['priority']['high'] = [
    '#type' => 'textfield',
    '#title' => t('High'),
    '#default_value' => $options['priority']['high'],
  ];

  $form['console_log_options']['priority']['normal'] = [
    '#type' => 'textfield',
    '#title' => t('Normal'),
    '#default_value' => $options['priority']['normal'],
  ];

  $form['console_log_options']['method'] = [
    '#type' => 'select',
    '#title' => t('Javascript method'),
    '#default_value' => $options['method'],
    '#options' => [
      'log' => 'console.log',
      'info' => 'console.info',
      'warn' => 'console.warn',
      'error' => 'console.error',
    ],
  ];

  return system_settings_form($form);
}
