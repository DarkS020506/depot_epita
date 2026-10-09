#!/bin/bash

while true; do
    printf "> "
    read ligne
    if [[ "$ligne" == "exit" ]]; then
        break
	exit 2
    fi
    resultat=$(( $ligne ))
    echo "$resultat"
done

