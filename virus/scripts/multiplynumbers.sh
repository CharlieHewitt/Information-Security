#!/bin/bash

echo -e "Enter first number:"
read num1
echo -e "Enter second number:"
read num2
num3=$(($num1*$num2))
echo -e "$num1 * $num2 = $num3"
