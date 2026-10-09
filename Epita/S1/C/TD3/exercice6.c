#include <stdio.h>

int viceMaxTab(int tab[], int n){
	int max=tab[0];
	int indice_max=0;
	for (int i=0; i<n; i++){
		if (max<tab[i]){
			max=tab[i];
			indice_max=i;
		}
	}
	int max_2=tab[0];
	int indice_max_2=0;
	for (int i=0; i<n; i++){
		if (tab[0]>max_2 && max>=tab[0]){
			max_2=tab[0];
			indice_max_2=i;
		}
	}
	printf("%d\n%d",max_2,indice_max_2);
	return indice_max_2;
}

int main(){
	int array[5]={5,-6,12,27,2};
	int n=5;
	viceMaxTab(array,n);
	return 0;
}
