/* Nom: BOZONNIER Sylvain
 * Date: 02/12/2025
 * Groupe: A
*/ 

#include <stdio.h>

int palinP(char* mot)
{
    char *debut=mot;
    char *fin=mot;
    while (*fin!='\0') {
        fin++;
    }
    fin--;
    while (debut < fin) {
        char c1=*debut;
        char c2=*fin;
        if (c1>='A' && c1<='Z') c1=c1+('a'-'A');
        if (c2>='A' && c2<='Z') c2=c2+('a'-'A');
        if (c1!=c2){
            return 0;
        }
        debut++;
        fin--;
    }
    return 1;
}
