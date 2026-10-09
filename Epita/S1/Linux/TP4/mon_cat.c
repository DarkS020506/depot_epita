#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 4096
void cat_file(FILE *file) {
    char buf[BUF_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buf, 1, BUF_SIZE, file)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            if (buf[i] == '\n') {
                fwrite("$", 1, 1, stdout);
            }
            fwrite(&buf[i], 1, 1, stdout);
        }
    }

    if (ferror(file)) {
        perror("Erreur de lecture du fichier");
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        cat_file(stdin);
    } else {
        for (int i = 1; i < argc; i++) {
            FILE *file = fopen(argv[i], "rb");
            if (!file) {
                perror(argv[i]);
                continue;
            }

            cat_file(file);
            fclose(file);
        }
    }

    return 0;
}
