repertoire=""
nom=main
extension=c
for ((i=1;i<=$#;i++));do
	arg=${!i}
	if [["$arg"=="-r"]];then
		next=$((i+1))
		repertoire="${!next}"
	elif [["$arg"=="-n"]];then
		next=$((i+1))
		nom="${!next}"
	elif [[$"$arg"=="-e"]];then
		next=$((i+1))
		extension=${!next}
	fi
done
fichier="$repertoire$nom.$extension"
echo "$fichier"

