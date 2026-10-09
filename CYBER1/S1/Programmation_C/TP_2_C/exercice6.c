#include <stdio.h>

int evenCount(int n){
	int nb_impaire=0;
	while (n>0){
		if ((n%10)%2==1){
			nb_impaire+=1;
			n=n/10;
		}else{
			n=n/10;
		}
	}
	return nb_impaire;
}

int main(){
	int n, resultat;
	printf("Entrer n: ");
	scanf("%d",&n);
	resultat=evenCount(n);
	printf("%d",resultat);
	return 0;
}
