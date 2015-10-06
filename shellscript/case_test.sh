#!/bin/bash

echo "input a number: "
read num

case $num in
1)
echo "it is January";;
2)
echo "it is February";;
*)
echo "the others"
esac

