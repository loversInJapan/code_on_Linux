#!/bin/bash

str1='abcd'
str2='abqw'

if [$str1 \> $str2 ]
then 
	echo "str1 is greater than str2"
elif [ $str1 \< $str2 ]
then 
	echo "str1 is less than str2"
elif [ $str1 = $str2 ]
then
	echo "str1 is equal to str2"
fi

