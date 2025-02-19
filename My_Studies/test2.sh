#!/bin/bash

if tty -s ; then
	echo "Success"
else
	echo "Failure"
fi
