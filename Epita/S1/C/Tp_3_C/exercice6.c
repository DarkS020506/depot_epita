/* 
 * Nom: BOZONNIER Sylvain
 * Date:21/11
 * Groupe: A
*/

#include <stdio.h>

int countChar(char tab[], int n, char lettre){
	int nombre=0;
	for (int i=0; i<n; i++){
		if (tab[i]==lettre){
			nombre=nombre+1;
		}
	}
	return nombre;
}
