#include <stdio.h>
#include <stdlib.h>
int exponation(int n, int e, int m){
    int reste=1;
    for (int i=1; i<=e; i++){
        reste=(reste*m)%n;
    }
    return reste;
}

int génération_cle(){
    int a=rand(0, 1000);
    int b=rand(0, 1000);
    return a,b;
}

int module_chiffrement(int p, int q){
    return p*q;
}

int indice_Euler(int p, int q){
    return (p-1)*(q-1);
}

int exposant_de_chiffrement(int max){
    int exposant= 1;
    for(int i=1; i<max; i++){
        if (max%i==0){
            exposant=i;
        }
    }
    return exposant;
}

int inverse_modulaire(int a, int modulo){
    for (int i=1; i<modulo; i++){
        if ((a*i)%modulo==1){
            return i;
        }
    }
    return -1;
}
int main(){
    int valeur=exponation(40,2,10);
    printf("%d",valeur);
}