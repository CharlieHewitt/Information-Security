#!/bin/bash

# assuming script is called from virus, will still work (will work away the error message)
cd src

# creating test directory
cp -a ../scripts ../test
cp test.sh ../test

echo -e "created test directory"