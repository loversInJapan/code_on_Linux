#!/bin/bash

echo "please type first number:"
read param1

echo "please type second number:"
read param2

result=$[$param1+$param2]

echo "the result is :"$result
