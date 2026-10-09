#include <stdio.h>

int main(){
	printf("prompt$exercice2\n");
	int entier;
	printf("Entrer un entier: ");
	scanf("%d", &entier);
	printf("\n");
	if (entier%3==0 && entier%7==0){
		printf("Multiple de 21.");
	}else{
		printf("Non multiple de 21 \n");
	}
	return 0;
}
