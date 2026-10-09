logfile="quibosse.log"

who | sort -k 3,3 -k 4,4 | tee -a "$logfile"

echo "ajouté à $logfile"
