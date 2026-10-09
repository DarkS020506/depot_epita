file="etc.$(date +%y.%m.%d)"
ls  /etc > "$file"
echo $(wc -l < "$file")
