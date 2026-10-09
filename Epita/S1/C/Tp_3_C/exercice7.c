/*
 * Nom: BOZONNIER Sylvain
 * Date: 21/11/2025
 * Groupe: A
*/

#include <stdio.h>

int countLettre(char tab[], int n, char lettre) {
    int counteur=0;
    char autre_case;
    if (lettre>='a' && lettre<='z'){
        autre_case=lettre-32; 
    }else if (lettre>='A' && lettre<='Z'){
        autre_case=lettre+32; 
    }else{
        autre_case=lettre; 
    }
    for (int i=0; i<n; i++){
        if (tab[i]==lettre || tab[i]==autre_case) {
            counteur+=1;
        }
    }
    return counteur;
}
