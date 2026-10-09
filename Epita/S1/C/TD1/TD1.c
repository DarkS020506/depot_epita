#include <stdio.h>

int main(){
	printf("prompt$exercice1\n");
	int entier;
	printf("Entrez un entier: ");
	scanf("%d", &entier);
	int quotient;
	quotient=entier/3;
	int reste;
	reste=entier%3;
	printf("Le quotient est %d. \n", quotient);
	printf("Le reste est %d. \n", reste);
	return 0;
}
