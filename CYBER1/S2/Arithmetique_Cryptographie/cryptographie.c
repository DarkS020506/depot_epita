#include <stdio.h>
#include <stdlib.h>

int reste_division(int a, int b){
    int reste=a%b;
    return reste;
}

int quotient_division(int a, int b){
    int quotient=a/b;
    return quotient;
}

int *diviseur(int n, int *taille) {
    int *liste = malloc(1000 * sizeof(int));
    int y = 0;
    for (int i = -n; i <= -1; i++) {
        if (n % i == 0) {
            liste[y] = i;
            y++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            liste[y] = i;
            y++;
        }
    }
    *taille = y;
    return liste;
}

int main() {
    int n;
    int taille;
    int *diviseurs;

    printf("Entrez un nombre : ");
    scanf("%d", &n);
    diviseurs = diviseur(n, &taille);
    printf("Diviseurs de %d :\n", n);
    for (int i = 0; i < taille; i++) {
        printf("%d ", diviseurs[i]);
    }
    printf("\n");
    free(diviseurs);
    return 0;
}
