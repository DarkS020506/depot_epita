/* Nom: BOZONNIER Sylvain
 * Date: 17/12/2025
 * Groupe: A
*/

#include <stdio.h>
#include <stdlib.h>

struct account createAccount ( int id , char role );

struct account{
	int id;
	char role;
};

struct account createAccount ( int id , char role ){
	struct account nv_compte;
	nv_compte.id=id;
	nv_compte.role=role;
	return nv_compte;
}

