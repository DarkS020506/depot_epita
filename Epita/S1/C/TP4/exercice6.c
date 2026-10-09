/* Nom: BOZONNIER Sylvain
 * Date: 02/12/2025
 * Groupe: A
*/
#include <stdio.h>
int searchCarP(char *pS, char car){
	while (*pS!='\0'){
		if (*pS==car){
			return 1;
		}
		pS++;
	}
	return 0;
}
