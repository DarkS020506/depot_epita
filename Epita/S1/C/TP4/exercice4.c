/* Nom: BOZONNIER Sylvain
 * Date: 02/12/2025
 * Groupe: A
*/

#include <stdio.h>

int *minP(int *pA, int *pB, int *pC){
	if (*pA<=*pB && *pA<=*pB){
		return pA;
	}else if(*pB<=*pA && *pB<=*pC){
		return pB;
	}else{
		return pC;
	}
}
