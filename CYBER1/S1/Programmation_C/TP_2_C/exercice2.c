#include <stdio.h>
int min(int a, int b, int c){
	if (a<=b && a<=c){
		printf("%d",a);
	}else if (b<=a && b<=c){
		printf("%d",b);
	}else{
		printf("%d",c);
	}
	return 0;
}

int main(){
	int a, b, c;
	printf("Entrer a:");
	scanf("%d",&a);
	printf("Entrer b:");
	scanf("%d",&b);
	printf("Entrer c:");
	scanf("%d",&c);
	min(a,b,c);
	return 0;
}
