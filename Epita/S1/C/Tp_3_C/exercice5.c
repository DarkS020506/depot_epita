/* 
 * Nom: BOZONNIER Sylvain
 * Date: 21/11
 * Groupe: A 
*/ 

#include <stdio.h>

void reverseTab(int tab[], int n) {
  int i;
  int temporaire;
  for (i=0; i<(n/2); i++){
    temporaire=tab[i];
    tab[i]=tab[n-1-i];
    tab[n-1-i]=temporaire;
  }
  for (i=0; i<n; i++){
    printf("%d",tab[i]);
    if (i<n-1){
      printf(" ");
    }
  }
  printf("\n");
}
