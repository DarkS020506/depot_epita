#include <stdio.h>

int main(){
	printf("prompt$exercice3");
	printf("\n");
	int n;
	printf("Entrer n: ");
	scanf("%d",&n);
	if (n<7){
		return 0;
	}else{
		for (int i=7; i<=n; i=i+7){
			printf("%d\n",i);
		}
	}
	return 0;
}
