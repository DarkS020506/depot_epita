#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc,  char *argv[]){
	bool n_av=false;
	bool e_av=false;
	int i=1;
	while (i<argc){
		if (strcmp(argv[i],"-n")==0){
			n_av=true;
		}else if (strcmp(argv[i],"-E")==0){
			e_av=false;
		}else if (strcmp(argv[i],"-e")==0){
		}else{
			break;
		}
		i++;

	}
	for (int j=i; j<argc;j++){
		printf("%s",argv[j]);

		if (j<argc-1){
			printf(" ");
		}
	}	
	if (n_av == false ){
		printf("\n");
	}
	return 0;
}
