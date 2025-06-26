<?php
define ('DB_NAME', 'wordpress');
define ('DB_USER', 'wpuser');
define ('DB_PASSWORD', 'password');
define ('DB_HOST', 'mariadb');
define ('DB_CHARSET', 'utf8mb4');
define ('DB_COLLATE', '');

$table_prefix =  '_wp';

define ('WP_DEBUG', false);
if ( ! defined ('ABSPATH') )
{
	define ('ABSPATH', __DIR__ . '/');
}

require_once ABSPATH . 'wp-settings.php';
