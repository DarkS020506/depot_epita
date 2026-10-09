#include <stdio.h>

int isEven(int n){
	return n%2;
}

void allEvent(int n){
	for (int i=0; i<=n; i++){
		int pair=isEven(i);
		if (pair==0){
			printf("%d",i);
			printf("\n");
		}
	}
}
int factorielle(int n){
	int produit=1;
	for (int i=0; i<=n; i++){
		produit=produit*i;
		printf("%d",i);
		printf("\n");
		printf("%d",produit);
	}
	printf("%d",produit);

}
int main(){
	int recus;
	recus=isEven(3);
	printf("%d",recus);
	recus=isEven(2);
	printf("%d",recus);
	printf("\n");
	allEvent(50);
	factorielle(5);
	return 0;
}
