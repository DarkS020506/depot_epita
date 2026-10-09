#!/bin/bash

if [ $# -lt 1 ] || [ $# -gt 3 ]; then
    echo "Usage: $0 [FIRST [INCREMENT]] LAST" >&2
    exit 1
fi
if [ $# -eq 1 ]; then
    first=1
    increment=1
    last=$1
elif [ $# -eq 2 ]; then
    first=$1
    increment=1
    last=$2
else
    first=$1
    increment=$2
    last=$3
fi
if [ "$increment" -eq 0 ]; then
    exit 0
fi
i=$first
if [ "$increment" -gt 0 ]; then
    while [ "$i" -le "$last" ]; do
        echo "$i"
        i=$((i + increment))
    done
else
    while [ "$i" -ge "$last" ]; do
        echo "$i"
        i=$((i + increment))
    done
fi
