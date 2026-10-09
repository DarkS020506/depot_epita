#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	int value=open("factorielle_recu.sh",O_RDONLY);
	if ( value == -1){
		printf("error");
	}
	char buffer[1024];
	int bytsread;

	while ((bytsread=read(value,buffer,sizeof(buffer)-1))>0){
		buffer[bytsread]= '\0';
		printf("%s",buffer);
	}
	close(value);
	return 0;

}
