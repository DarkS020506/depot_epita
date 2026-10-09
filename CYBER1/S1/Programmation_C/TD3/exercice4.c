#include <stdio.h>

int countTab(int tab[], int n, int value){
	int nb=0;
	for (int i=0; i<n; i++){
		if (tab[i]>=value){
			nb=nb+1;
		}
	}
	printf("%d",nb);
	return nb;
}

int main(){
	int tableau[5]={5,-6,89,12,5};
	int n=5;
	int valeur=0;
	countTab(tableau,n,valeur);
	return 0;
}
