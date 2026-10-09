#include <stdio.h>

int main(){
	printf("prompt$exercice3\n");
	int numA=0;
	printf("Entrer un premier entier: ");
	scanf("%d", &numA);
	int numB=0;
	printf("Entrer un second entier: ");
	scanf("%d", &numB);
	if (numA%2==0 || numB%2==0){
		printf("Un des entiers est pair.\n");
	}else{
		printf("Les deux entiers sont impaires.\n");
	}
	return 0;
}
