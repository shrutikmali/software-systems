#!/bin/bash

number=2
counter=1

while [ $counter -le 10 ]
do
	result=$((number * counter))
	echo "$number * $counter = $result"
	counter=$(($counter + 1))
done
