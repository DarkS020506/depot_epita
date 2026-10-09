#include <stdio.h>

int pgcd(int a, int b){
    int q=a;
    if (a>=b){
        q=b;
    }
    while (q>0){
        if (a%q==0 && b%q==0){
            return q;
        }
        q-=1;
    }
    return 1;
}

int main(){
    int a=pgcd(12,66);
    printf("resultat: %d",a);
    return 1;
}