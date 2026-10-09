/* Nom: BOZONNIER Sylvain
 * Date: 17/12/2025
 * Groupe: A
*/

#include <stdio.h>
#include <stdlib.h>


char getRole ( struct account myAccount );
void setRole ( struct account * myAccountP , char newRole ) ;

struct account{
	int id;
	char role;
};

char getRole ( struct account myAccount ){
	return myAccount.role;
}

void setRole ( struct account * myAccountP , char newRole ){
	myAccountP -> role=newRole;
}

