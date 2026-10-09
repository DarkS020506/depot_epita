#include <stdio.h>

int main(){
	int tableau[3];
	int valeur;
	for (int i=0; i<3; i++){
		printf("Entrer la valeur %d: ",i);
		scanf("%d",&valeur);
		tableau[i]=valeur;
	}
	for (int i=0; i<3; i++){
		
		printf("%d\n",tableau[i]);
	}

	return 0;
}
