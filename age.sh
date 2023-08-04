#!/bin/bash

if [ $# -ne 1 ]
then
	echo "Enter only one age"
elif [ $1 -lt 18 ]
then
	echo "You can't drive"
else
	echo "You can drive"
fi

