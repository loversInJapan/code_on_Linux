#!/bin/bash

echo "please type a number"
read num
if [ $num -gt 10 ] || [ $num -eq 10 ]
then 
	echo "num is greater than 10 or equal to 10"
elif [ $num -gt 5 ] && [ $num -lt 10 ]
then 
	echo "num is greater than 5 and less than 10"
else
	echo "num is less than 5"
fi
