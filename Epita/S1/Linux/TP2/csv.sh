L=$(cat ligne.txt)
C=$(cat calonne.txt)
ligne=$(sed -n "${l}p" fichier.csv)
valeurs=$(echo "$ligne" | cut -d';' -f"$C")
echo"$valeurs"
