#include <stdio.h>
#include <stdlib.h>

int * append ( int * tabP , int size , int value ){
	int *tabs;
	tabs=malloc((size*sizeof(int))+1);
	if (tabs==NULL){
		exit(-1);
	}
	for (int i=0; i<size; i++){
		tabs[i]=tabP[i];
	}
	tabs[size]=value;
	free(tabP);
	return tabs;
}
