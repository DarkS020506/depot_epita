#!/usr/bin/env bash
max="$1"
min="$1"
if [[ $# -eq 0 ]];then
	echo ""
	exit 2
fi
if [[ $# -gt 1 ]];then
	
	while [[ "$#" -gt 0 ]];do
		suivant=$1
		if [[ $suivant -gt $max ]];then
			max=$suivant
		fi

		if [[ $suivant -lt $min ]]; then
			min=$suivant
		fi
		shift
	done
fi
echo "$min $max" 
