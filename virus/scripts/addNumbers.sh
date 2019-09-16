#!/bin/bash

echo -e "Please insert the first number"
read num1
echo -e "Please insert the Second number"
read num2
added=$(($num1 + $num2))
echo -e "result = $added"
