/* Nom: BOZONNIER Sylvain
 * Date: 17/12/2025
 * Groupe: A
*/

#include <stdio.h>
#include <stdlib.h>

int * tenA ( int * tab , int size ) ;

int * tenA ( int * tab , int size ) {
	int *tabs;
	tabs=malloc(size*sizeof(int));
	if (tabs==NULL){
		printf("Malloc error: malloc");
		exit(-1);
	}
	for (int i=0; i<size; i++){
		tabs[i]=tab[i]*10;
	}
	return tabs;
}
