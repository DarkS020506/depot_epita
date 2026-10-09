#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int value=0;
	for (int i=1; i<argc ; i++){
		int nombre=open(argv[i],O_RDONLY);
		if (nombre != -1){
			value++;
		}
		close(nombre);
	}

	printf("%d",value);
}
