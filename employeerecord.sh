#!/bin/bash

run=1

while [ $run -eq 1 ]
do
	echo "Enter 1 to add a record"
	echo "Enter 2 to delete a record"
	echo "Enter 3 to list all records"
	echo "Enter 4 to sort records"
	echo "Press -1 to quit"
	read option

	if [ $option -eq 1 ]
	then
		# Add record
		echo "Adding record"
		echo "Enter employee name"
		read empName
		echo "Enter employee id"
		read empId
		echo "Enter employee telephone number"
		read empNum

		echo "$empId $empName $empNum" >> emp_info.txt

	elif [ $option -eq 2 ]
	then
		# Delete a record
		echo "Deleting record"
		echo "Enter id of record to delete"
		read idToDelete

		grep -v "^$idToDelete" emp_info.txt > emp_info_temp.txt
		mv emp_info_temp.txt emp_info.txt

	elif [ $option -eq 3 ]
	then
		# List all records
		echo "Listing records"
		cat emp_info.txt
	elif [ $option -eq 4 ]
	then
		# Sort records
		echo "Sorting records"
		sort emp_info.txt
	elif [ $option -eq -1 ]
	then
		# Quit
		run=0
	else
		echo "Incorrect choice"
	fi
done	

