#!/bin/bash

rm -rf /var/www/html
mkdir -p /var/www/html
cd /var/www/html
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
./wp-cli.phar core download --allow-root
until ping -c 1 mariadb > /dev/null 2>&1;
do
	echo "Waiting for mariadb answering on the web"
	sleep 1
done
./wp-cli.phar config create --dbname="$WORDPRESS_DB_NAME" --dbuser="$WORDPRESS_DB_USER" --dbpass="$WORDPRESS_DB_PASS" --dbhost="$WORDPRESS_DB_HOST" --allow-root
./wp-cli.phar core install --url="$WORDPRESS_URL" --title="$WORDPRESS_TITLE" --admin_user="$WORDPRESS_ADMIN_USER" --admin_password="$WORDPRESS_ADMIN_PASSWORD" --admin_email="$WORDPRESS_ADMIN_EMAIL" --allow-root

php-fpm7.4 -F
