#!/bin/bash

if (($1==0)); then
    echo 1
else
    prev=$(./factorielle_recursive.sh $(($1-1)))
    echo $(($1*prev))
fi

