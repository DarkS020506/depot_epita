cut -d: -f1,7 /etc/passwd | sort -t: -k2,2 -k1,1 | tr ':' ' ' 
