if (($*==1)) then
	echo $1
	echo "succès"
	exit 1
else
	echo "usage: statut;sh PARAMETRE" >&2
	exit 2
fi
