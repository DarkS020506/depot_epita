#!/usr/bin/env bash

varriable=0
if [[ $# -gt 0 ]];then
	echo ""
	exit 2
fi
for element in *.doc ;do
	if [[ $element == "*.doc" ]];then	
		varriable=0
		echo 0
		exit 2
	fi
	varriable=$(( $varriable + 1))
done
echo $varriable
exit 1
