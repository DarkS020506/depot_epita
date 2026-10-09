#include <stdio.h>
#include <stdlib.h>

struct account{
	int id;
	char role;
};

char getRole ( struct account myAccount ){
	return myAccount.role;
}

void setRole ( struct account * myAccountP , char newRole ) {
	myAccount->role=newRole;
}
