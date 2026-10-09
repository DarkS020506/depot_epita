#!/usr/bin/env bash

nombre=$1
produit=1 
if [[ $# -gt 1 ]];then
	echo ""
	exit 2
fi
if [[ $# -eq 0 ]];then
	echo ""
	exit 2
fi
if [[ $nombre -lt 0 ]];then
	echo ""
	echo ""
	exit 2
fi
if [[ $nombre -eq 0 ]];then
	echo 1
else
	while [[ $nombre -gt 0 ]]; do
		produit=$(( $produit * $nombre))
		nombre=$(( $nombre -1))
	done
	echo $produit
fi
