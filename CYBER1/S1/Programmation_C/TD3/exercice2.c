#include <stdio.h>

void printTab(int tab[], int n){
	for (int i=0; i<n; i++){
		printf("%d\n",tab[i]);
	}
}
int main(){
	int tableau[5]={12,5,0,-2,846};
	int n=5;
	printTab(tableau,n);
	return 0;
}
