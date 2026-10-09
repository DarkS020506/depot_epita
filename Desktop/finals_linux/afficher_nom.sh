#!/usr/bin/env bash

repertoire=""
nom="main"
extension="c"
modif_r=0
modif_n=0
modif_e=0
if [[ $# -eq 1 ]];then
	echo ""
	exit 2
fi
while [[ "$#" -gt 0 ]];do
	case "$1" in
		-r)
			repertoire=$2
			modif_r=1
			shift 2
			;;
		-n)
			nom=$2
			modif_n=1
			shift 2
			;;
		-e)
			extension=$2
			modif_e=1
			shift 2
			;;
		*)
			echo ""
			shift
			exit 2
			;;
	esac
done
if [[ -z $repertoire ]];then
	continue
else
	repertoire=$repertoire"/"
fi

if [[ -z $extension ]];then
	echo "$repertoire""$nom"
else
	echo "$repertoire""$nom"."$extension"
fi

