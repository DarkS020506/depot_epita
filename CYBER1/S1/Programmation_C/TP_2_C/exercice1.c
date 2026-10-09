#include <stdio.h>

int main(){
	int entier1, entier2, somme, produit;
	printf("prompt$exercice1");
	printf("\n");
	printf("Entrer un entier: ");
	scanf("%d",&entier1);
	printf("Entrer un entier: ");
	scanf("%d",&entier2);
	somme=entier1+entier2;
	produit=entier1*entier2;
	printf("La somme est ");
	printf("%d\n", somme);
	printf("Le produit est ");
	printf("%d\n", produit);
	return 0;
}	
