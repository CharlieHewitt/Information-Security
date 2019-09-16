#!/bin/bash

# if script is called from virus (../src)
if [ $(find . -type d -name src | grep src) ]
then
    cd src
fi

# removing test directory
rm -r ../test

echo -e "removed test directory"