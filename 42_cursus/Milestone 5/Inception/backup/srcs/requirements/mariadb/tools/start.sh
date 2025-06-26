#!/bin/bash

mysqld_safe --skip-networking &
pid="$!"

until mysqladmin ping --silent;
do
	echo "waiting mariadb starts"
	sleep 1
done

envsubst < initializer.sql > init.sql

mysql -u root < /init.sql

mysqladmin shutdown

wait "$pid"

exec mysqld_safe
