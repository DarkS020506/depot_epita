for file in *.c *.h; do
	if [ -f "$file" ];then
		lines=$(wc -l < "$file")
		echo "$file $lines"
	fi
done | sort -k2 -nr
