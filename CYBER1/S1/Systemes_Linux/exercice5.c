#include <stdio.h>
#include <stdlib.h>

struct student{
	char *nom;
	int *notes;
	int noteC;

};

struct student creatDefault(){
	struct student Default;

	Default.notesC=3;

	char *nomJ="John Doe";
	Default.nom=malloc(sizeof(char)*sizeof("John Doe"));
	if (Default.nom == NULL){
		exit(-1);
	}
	for (int i=0; i<9; i++){
		Default.nom[i]=nomJ[i];
	}

	Default.notes=malloc(sizeof(int)*Default.ntoesC);
	if (Default.notes == NULL){
		exit(-1);
	}
	for (int i=0; i<3; i++){
		Default.notes[i]=10;
	}
	return Default;

}


