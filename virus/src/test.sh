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

# find . -name "*.sh"? or "./*.sh"?
# need to for loop over files ending with ./*.sh
# if [ $(cat file | grep -c "#addedvirus") -gt 0 ]
# add virus else do w/e
# -> Fix the for loop
