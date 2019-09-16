#!/bin/bash

test= find . -name "*.sh"

echo $test
echo $(grep -c "#virusadded" *.sh)
# if [ $(grep -c "#virusadded" $test) -eq 1 ]
# then
# echo "got through if"
# else
# echo "#virusadded" >> $test
# fi

