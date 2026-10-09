#!/bin/bash

while [[ "$#" != 0 ]]; do
    echo "$1 :"
    
    if [[ -d "$1" ]]; then
        ls $1
	
    elif [[ -f "$1" ]]; then
        cat $1 | cut -d ':' -f 1
    else
        echo "Pas une entrée valide"
	exit 2
    fi
    
    shift
done
