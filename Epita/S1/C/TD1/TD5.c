#include <stdio.h>
#include <math.h>

int main(){
	printf("prompt$exercice5\n");
	int entier;
	printf("Entrer un entier: ");
	scanf("%d",&entier);

	int somme=0;
	int unite=0;

	for (; entier!=0;){
		unite=entier%10;
		somme += unite;
		entier=entier/10;
	}
	printf("%d",somme);
	return 0;
}
