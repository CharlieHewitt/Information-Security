#!/bin/bash

# if script is called from virus (../src)
if [ $(find . -type d -name src | grep src) ]
then
    cd src
fi

# creating test directory
cp -a ../scripts ../test
cp test.sh ../test

echo -e "created test directory"