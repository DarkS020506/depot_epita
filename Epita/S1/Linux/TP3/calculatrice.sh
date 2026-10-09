#!/bin/bash

while true; do
    printf "> "
    read ligne
    if [[ "$ligne" == "exit" ]]; then
        break
    fi
    resultat=$(( $ligne ))
    echo "$resultat"
done

