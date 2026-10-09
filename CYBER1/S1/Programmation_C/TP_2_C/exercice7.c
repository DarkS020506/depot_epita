#include <stdio.h>

void pyramid(int n){
	int nb_espace;
	int nb_etoile=1;
	for (int i=0; i<(n/2+1); i++){
		nb_espace=(n-nb_etoile)/2;
		for (int y=0; y<nb_espace; y++){
			printf(" ");
		}
		for (int y=0; y<nb_etoile; y++){
			printf("*");
		}
		printf("\n");
		nb_etoile+=2;
	}
}
int main(){
	int n;
	printf("Entrer n: ");
	scanf("%d", &n);
	pyramid(n);
}
