#!/bin/bash
nombre=0
for fichier in *;do
	nombre=$(( nombre + 1 ))
	if [ -d "$fichier" ];then
		echo "$fichier est un repertoire"
	else
		echo "$fichier est un fichier"
	fi
done
echo "il y a en tout $nombre fichiers"

