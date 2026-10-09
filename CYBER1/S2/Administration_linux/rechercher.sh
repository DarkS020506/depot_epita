#!/bin/bash
echo "Entrez un mot à chercher:"
read MOT
grep -i "$MOT" /var/log/syslog
