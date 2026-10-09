#include <stdio.h>
#include <stdlib.h>

int palinP(char *mot){
	int i=0;
	while (mot[i]!='\0'){
		char c1=mot[i];
		if ( c1 >='A' && c1<='Z'){
			c1=c1+32;
		}
		if ( c2 >= 'A' && c2<='Z'){
			c2=c2+32;
		}
		if (c1!=c2){
			return 0;
		}
		i++;
	}
	return 1;
}
