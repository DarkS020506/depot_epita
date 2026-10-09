/* Nom: BOZONNIER Sylvain
 * Date: 02/12/2025
 * Groupe: A
*/

#include <stdio.h>
char *deleteHalf(char *mot){
	static char nv_mot[100];
	int i=0;
	while (*mot!='\0'){
		if (i%2==0){
			nv_mot[i]=*mot;
		}else{
			nv_mot[i]='_';
		}
		mot++;
		i++;
	}
	nv_mot[i]='\0';
	return nv_mot;
}
