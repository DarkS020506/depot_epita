#!/bin/bash

opt_n=false
opt_s=false
opt_E=false

while getopts "nsE" opt; do
    case $opt in
        n) opt_n=true ;;
        s) opt_s=true ;;
        E) opt_E=true ;;
        *)
            echo "Usage: $0 [-n] [-s] [-E] [file ...]"
            exit 1
            ;;
    esac
done
shift $((OPTIND - 1))
line_number=1
previous_empty=false
read_file() {
    local file="$1"
    while IFS= read -r line || [ -n "$line" ]; do
        if $opt_s && [ -z "$line" ]; then
            if $previous_empty; then
                continue
            fi
            previous_empty=true
        else
            previous_empty=false
        fi
        if $opt_n; then
            printf "%6d  " "$line_number"
            ((line_number++))
        fi
        if $opt_E; then
            echo "${line}\$"
        else
            echo "$line"
        fi

    done < "$file"
}
if [ $# -eq 0 ]; then
    read_file /dev/stdin
else
    for file in "$@"; do
        if [ -r "$file" ]; then
            read_file "$file"
        else
            echo "mon_cat.sh: $file: No such file or not readable" >&2
        fi
    done
fi
