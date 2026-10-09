#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	if (argc != 3){
		fprintf(stderr,"usage : copier File1 File2\n");
		exit(3);
	}
	int fd1=open(argv[1],O_RONLY);
	if (fd1==-1){
		err(2,argv[1]);
	}
	int fd2=open(argv[2],O_RONLY);
	if (fd1==-1){
		err(2,argv[2]);
	}

	return 0;
}
