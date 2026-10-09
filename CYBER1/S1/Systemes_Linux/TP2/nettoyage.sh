logfile="nettoyage.log"
touch "$logfile"

find . -maxdepth 1 -type f -mtime +3 | while read -r fichier; do
	echo "Supprimer le fichier: $fichier? (o/n)"
	read -r reponse
	case "$reponse" in [oO])
		rm -f "$fichier"
		echo "$date '+%y -%m-%d %H:%M:%D') - $fichier supprimeé" >> "$logfile"
		echo "fichier supprimé"
		;;
	*)
		echo "fichier conservé"
		;;
	esac
done
