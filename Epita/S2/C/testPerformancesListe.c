#include <stdio.h>
#include <stdlib.h>
#include "liste.c"

int main(int argc, char *argv[]) {
    if (argc != 4) return EXIT_FAILURE;

    int type_structure = atoi(argv[1]);
    int n_operations = atoi(argv[2]);
    int iterations = atoi(argv[3]);
    int K = 3;
    const char* val = "test";

    for (int i = 0; i < iterations; i++) {
        liste* l = creer(n_operations * K);
        if (l == NULL) continue;
        
        int count = 0;
        while (count < n_operations) {
            for (int j = 0; j < K && count < n_operations; j++) {
                if (type_structure == 0) {
                    ajouter(l, l->taille, val);
                } else {
                    ajouter(l, 0, val);
                }
                count++;
            }
            retirer(l, 0);
        }
        supprimer(l);
    }

    return EXIT_SUCCESS;
}
