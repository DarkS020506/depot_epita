#!/bin/bash
existe=0
for fichier in $(ls);do
	if [[ test.txt == $fichier ]];then
		existe=1
	fi
done
if [[ $existe  == 1 ]];then
	echo "le fichier test.txt existe!"
else
	echo "le fichier test.txt n'existe pas"
fi
