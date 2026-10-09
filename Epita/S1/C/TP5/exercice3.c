/* Nom: BOZONNIER Sylvain
 * Date: 17/12/2025
 * Groupe: A
*/

#include <stdio.h>
#include <stdlib.h>

int * append ( int * tabP , int size , int value ) ;

int * append ( int * tabP , int size , int value ){
	int *tabs;
	tabs=malloc((size+1)*sizeof(int));
	if (tabs==NULL){
		printf("Malloc error: malloc");
		exit(-1);
	}
	for (int i=0; i<size; i++){
		tabs[i]=tabP[i];
	}
	tabs[size]=value;
	free(tabP);
	return tabs;
}
