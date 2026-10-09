#include <stdio.h>

void tri_bulle(int tab[],int taille){
    int temp;
    for (int i=0; i<taille-1; i++){
        for (int j=0; j<taille-i-1;j++){
            if (tab[j]>tab[j+1]){
                temp=tab[j];
                tab[j]=tab[j+1];
                tab[j+1];
            }
        }
    }
}

void tri_selection(int tab[],int taille){
    int temp,indiceMin;
    for (int i=0; i<taille-1; i++){
        indiceMin=i;
        for (int j=i; j<taille; j++){
            if (tab[j]<tab[indiceMin]){
                indiceMin=j;
            }
        }
        if (indiceMin!=i){
            temp=tab[indiceMin];
            tab[indiceMin]=tab[i];
            tab[i]=temp;
        }
    }
}

void tri_insertion()