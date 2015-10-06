#!/bin/bash

echo "type an number: "
read val1;
if (( $val1 ** 2 > 20))
then
	((val2 = val1 ** 2))
echo "the square of $val1 is $val2"
fi
