/*
 * Nom : BOZONNIER Sylvain
 * Date : 21/11/2025
 * Groupe : A
*/

# include <stdio.h>

int minTab(int tab[], int n){
    int resultat=0;
    for (int i=0; i<n; i++){
        if (tab[i]<resultat){
            resultat=i;
        }
    }
    return resultat;
}
