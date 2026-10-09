#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	int value=0;
	for (int i=1; i<argc ; i++){
		if ( strcmp(argv[i],"-n")==0 && value == 0 && i+1<argc){
			value=1;
			continue;
		}else{
			if ( i + 1 >= argc){
				printf("%s",argv[i]);
			}else {
				printf("%s ",argv[i]);
			}
	
		}
	}
	
	if ( value == 0 ){
		printf("\n");
	}
	return 0;
}
