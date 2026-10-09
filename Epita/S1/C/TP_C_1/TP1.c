#include <stdio.h>

int main(int argc, char *argv[]){
	int un;
	printf("Limite :");
	scanf("%d",&un);
	for (int i=0; i<un+1; i++){
		if (i%2==0){
			printf("%d",i);
			printf("\n");
		}
	}
	
	return 0;
}
