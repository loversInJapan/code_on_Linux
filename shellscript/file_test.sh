#!/bin/bash

file='string_cmp.sh'

if [ -d $file ]
then
	echo "$file is a diractory"
fi

if [ -f $file ]
then 
	echo "$file is a file"
fi

if [ -x $file ]
then
	echo "$file is executable"
fi
