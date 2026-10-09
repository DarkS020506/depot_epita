#include <stdio.h>
#include <stdlib.h>

struct student{
	char *nom;
	int *notes;
	int notesC;
};

struct student createDefault () {
	struct student Default;
	char nomJohn="John Doe";
	Default.nom=malloc(sizeof("John Doe")*sizeof(char));
	if (Default.nom==NULL){
		exit(-1);
	}
	for (int i=0; i<9; i++){
		Default.nom[i]=nom[i];
	}
	Default.notesC=3;
	Default.notesC=malloc(sizeof(int)*3);
	if (Default.notesC==NULL){
		exit(-1);
	}
	for (int i=0; i<3; i++){
		Default.notesC[i]=10;
	}
	return Default;
}

void entrerNote ( struct student * myStudent ){
	for (int i=0; i<3;i++){
		int value;
		scanf("%d",&value);
		mysStudent -> notes[i]=value;
	}

