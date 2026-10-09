#!/bin/bash

factorielle(){
	if [ "$1" -eq 1 ];then
	       echo 1
       else
		precedent=$(($1 - 1))
		sous=$(factorielle $precedent)
		echo $(( $1 * $sous ))
	fi	
}
factorielle $1


