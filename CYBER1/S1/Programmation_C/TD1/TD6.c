#include <stdio.h>

int main(){
	printf("prompt$exercice6");
	printf("\n");
	int entier;
	printf("Entrer un entier: ");
	scanf("%d",&entier);
	printf("\n");
	int unité;
	int nombre=0;
	for(;entier!=0;){
		unité=entier%10;
		entier=entier/10;
		nombre=(nombre*10)+unité;
	}
	printf("%d", nombre);
	return 0;
}
