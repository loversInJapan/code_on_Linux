#!/bin/bash

echo "input yes | no"
read var
case $var in
yes | Yes)
echo "you said yes!"
echo "OK!";;
no | No)
echo "you said no"
echo "hehe";;
esac
