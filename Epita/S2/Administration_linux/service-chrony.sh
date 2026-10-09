#!/bin/bash 
if systemctl is-active chronyd > /dev/null;then
	echo "Le service chronyd est déjà actif."
else
	sudo systemctl start chronyd
	echo "Le service chronyd a été démarré."
fi

