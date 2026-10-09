#!/bin/bash

extension=".c"
nom="main"
repertoire=""
temp=0
while [[ "$#" != 0 ]];do
	if [[ "$1" == "-e" ]];then
		if [[ "$2" == "" ]];then
			extension="$2"
		else
			extension=".$2"
		fi
		shift
		shift
	elif [[ "$1" == "-n" ]];then
		nom="$2"
		shift
		shift
	elif [[ "$1" == "-r" ]];then
		repertoire="$2"
		shift
		shift
	else
		echo 2>"affiher_nom.sh : option $1 inconnue"
		temp=$(($temp+1))
		exit 2
		shift
	fi
done
if [[ $temp == 0 ]]; then
	if [[ $repertoire != "" ]];then
		echo "$repertoire/$nom$extension"
	else
		echo "$nom$extension"
	fi
fi

