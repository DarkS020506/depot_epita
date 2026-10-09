/*
 * Nom : BOZONNIER Sylvain
 * Date : 21/11/2025
 * Groupe : A
*/
 
# include <stdio.h>

int sumTab (int tab[], int n){
    int somme=0;
    for (int i=0; i<n; i++){
        somme=somme+tab[i];  
    }
    return somme;
}
