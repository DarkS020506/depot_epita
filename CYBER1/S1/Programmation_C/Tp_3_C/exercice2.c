/* 
 * Nom: BOZONNIER Sylvain
 * Date:21/11
 * Groupe: A
*/

#include <stdio.h>

int searchTab(int tab[], int n, int value){
	int value_2=0;
	for (int i=0; i<n; i++){
		if (tab[i]==value){
			value_2=1;
		}
	}
	return value_2;
}

