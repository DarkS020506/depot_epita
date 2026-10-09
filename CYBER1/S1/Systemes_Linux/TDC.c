#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char *nom;
	int age;
	float moyenne;
}etudiant;

void print_best_student(Etudiant* s1, Etudiant* s2, Etudiant* s3){
	if (s1->moyenne>=s2->moyenne && s1->moyenne>=s3->moyenne){
		printf("Le meilleur est : %s\n",s1->nom);
	}
}

int main(){
	etudiant pierre;
	etudiant paul;
	etudiant jack;

	printf("jack age: ");
	scanf("%d",&jack.age);

	printf("jack moyenne: ");
	scanf("%f",&jack.moyenne);
	
	jack.nom=malloc(5*sizeof(char));
	printf("jack nom: ");
	scanf("%s",jack.nom);

	print_best_student(&pierre,&paul,&jack);
	free(john);
	john=NULL;

	return 0;
}
