#Nom : BOZONNIER 
#Prenom: Sylvain

#!/bin/bash
i=10
while [ $i -gt 0 ]; do
	read -p "> " ligne
	if [ -z "$ligne" ]; then
		echo "error"
		i=-1
	elif [ "$ligne" = "exit" ];then
		echo "exit"
		i=-1
	else
		echo $(( $ligne1 ))
	fi

done
exit 1

