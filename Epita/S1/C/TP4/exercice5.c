
/* Nom: BOZONNIER Sylvain
 * Date: 02/12/2025
 * Groupe: A
*/

#include <stdio.h>

int searchValueP(int *pI, int n, int value){
	for (int i=0; i<n;i++){
		if (*pI==value){
			return 1;
		}
		pI++;
	}
	return 0;
}
