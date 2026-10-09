#!/bin/bash

if (($# == 0));then
	echo ""
	exit 1
else
	if ! [[ "$1" =~ ^-?[0-9]+$ ]];then
		echo "-1"
		exit 1
	fi
	variable=$1
	produit=1
	if (($1 < 0));then
		echo ""
		exit 1
	fi
	if (($1 == 0));then
		echo "1"
		exit 1
	else
		for ((i=1; i<=variable; i++)); do
			produit=$((produit*i))
		done
		echo $produit
	fi
fi
