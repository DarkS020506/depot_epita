#include <stdio.h>

int main(){
	printf("prompt$exercice\n");
	int a;
	printf("Entrer un entier: ");
	scanf("%d",&a);
	int b;
	printf("Entrer un entier: ");
	scanf("%d",&b);
	int ini;
	ini=a;
	if (b==0){
		printf("1");
	}else{
		for (int i=0;i<=b-2;i++){
			a=a*ini;
		}
	printf("%d",a);
	}

	return 0;
}
