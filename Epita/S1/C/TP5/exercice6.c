/* Nom: BOZONNIER Sylvain
 * Date: 17/12/2025
 * Groupe: A
*/

#include <stdio.h>
#include <stdlib.h>


struct student createDefault () ;
void entrerNote ( struct student * myStudent ) ;

struct student{
	int notesC;
	int *notes;
	char *nom;
};
struct student createDefault (){
	struct student basique;
	basique.notesC=3;
	char *nom="John Doe";

	basique.nom=malloc(sizeof("John Doe")*sizeof(char));
	if (basique.nom==NULL){
		printf("Malloc error: malloc");
		exit(-1);
	}
	for (int i=0; i<9; i++){
		basique.nom[i]=nom[i];
	}

	basique.notes=malloc(basique.notesC*sizeof(int));
	if (basique.notes==NULL){
		printf("Malloc error: malloc");
		exit(-1);
	}
	for (int i=0; i<basique.notesC;i++){
		basique.notes[i]=10;
	}
	return basique;
}

void entrerNote ( struct student * myStudent ){
	int nb_note;
	printf("Entrer le nombre :");
	scanf("%d",&nb_note);
	myStudent->notesC=nb_note;
	myStudent->notes=malloc(nb_note*sizeof(int));
	if (myStudent->notes==NULL){
		printf("Malloc error: malloc");
		exit(-1);
	for (int i=0; i<nb_note; i++){
		int nv_note;
		printf("Entrer le note :");
		scanf("%d",&nv_note);
		myStudent -> notes[i]=nv_note;
	}
}




