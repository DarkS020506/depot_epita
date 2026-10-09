#include <stdio.h>
#include <stdlib.h>

int * tripleA ( int * tab , int size ) {
	int *tabs;
	tabs=malloc(size*sizeof(int));
	for (int i =0; i<size; i++){
		tabs[i]=tab[i]*3;
	}
	return tabs;
}
