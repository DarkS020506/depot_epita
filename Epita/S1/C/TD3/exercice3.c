#include <stdio.h>

int sumTab(int tab[], int n){
	int somme=0;
	for (int i=0;i<n;i++){
		somme=somme+tab[i];
	}
	printf("%d",somme);
	return somme;
}

int main(){
	int tableau[5]={45,5,-6,487,-54};
	int taille=5;
	sumTab(tableau, taille);
	return 0;
}
