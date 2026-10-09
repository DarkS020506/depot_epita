/* Nom: BOZONNIER Sylvain
 * Date: 17/12/2025
 * Groupe: A
*/

#include <stdio.h>
#include <stdlib.h>

int *createArray(int size);

int *createArray(int size){
	int *tabs;
	tabs=malloc(size*sizeof(int));
	if (tabs==NULL){
		printf("Malloc error: malloc");
		exit(-1);
	}
	for (int i=0; i<size; i++){
		tabs[i]=0;
	}
	return tabs;
}

