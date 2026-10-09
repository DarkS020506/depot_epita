#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 N"
    exit 1
fi
if ! [[ "$1" =~ ^[0-9]+$ ]]; then
    echo "Erreur : l'argument doit être un entier positif."
    exit 2
fi
if [ "$1" -le 1 ]; then
    echo 1
else
    next_result=$(./$0 $(( $1 - 1 )))
    echo $(( $1 * next_result ))
fi
