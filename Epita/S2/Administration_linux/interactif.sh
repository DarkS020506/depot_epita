#!/bin/bash

echo "entrez le nom de l'utilisateur"
read NOM
echo "entrez l'âge de l'utilisateur"
read AGE
if [[ $AGE -ge 18 ]];then
	echo "salut $NOM qui a plus de 18 ans"
else
	echo "salut $NOM qui est encore mineur"
fi
