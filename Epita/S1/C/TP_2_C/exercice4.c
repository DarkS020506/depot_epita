#include <stdio.h>

int evenProd(int n){
	int produit=1;
	if (n==0){
		return 0;
	}else{
		for (int i=2; i<=n; i=i+2){
			produit=produit*i;
		}
	}
	return produit;

}

int main(){
	int n, produit;
	printf("Entrer n: ");
	scanf("%d",&n);
	produit=evenProd(n);
	printf("%d",produit);
	return 0;
}
