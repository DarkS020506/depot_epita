/* 
 * Nom: BOZONNIER Sylvain
 * Date:21/11
 * Groupe: A
*/

#include <stdio.h>

void swapValue(int tab[], int n, int i, int j){
	int nv_liste[n];
	for (int y=0;y<n;y++){
		if (y==i){
			nv_liste[y]=tab[j];
		}else if(y==j){
			nv_liste[y]=tab[i];
		}else{
			nv_liste[y]=tab[y];
		}
	}
	for (int h=0; h<n; h++){
		printf("%d",nv_liste[h]);
		printf(" ");
	}
}
