#include <stdio.h>

int maxTab(int tab[], int n){
	int max=tab[0];
	int indice_max=0;
	for (int i=0; i<n; i++){
		if (tab[i]>max){
			max=tab[i];
			indice_max=i;
		}
	}
	printf("%d\n%d", max, indice_max);
	return indice_max;
}

int main(){
	int tableau[5]={-6,5,12,-3,4};
	int nombre=5;
	maxTab(tableau,nombre);
	return 0;
}
