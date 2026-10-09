#include <stdio.h>

int sumDigits(int n){
	int somme=0;
	while (n>0){
		somme=somme+(n%10);
		n=n/10;
	}
	return somme;
}

int main(){
	int n, resultat;
	printf("Entrer n: ");
	scanf("%d",&n);
	resultat=sumDigits(n);
	printf("%d",resultat);
	return 0;
}
