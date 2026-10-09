#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1024
int copy_file(const char *source_path, const char *dest_path) {
    FILE *source_file, *dest_file;
    char buffer[BUFFER_SIZE];
    size_t bytes_read, bytes_written;
    source_file = fopen(source_path, "rb");
    if (source_file == NULL) {
        perror("Erreur lors de l'ouverture du fichier source");
        return -1;
    }
    dest_file = fopen(dest_path, "wb");
    if (dest_file == NULL) {
        perror("Erreur lors de l'ouverture du fichier destination");
        fclose(source_file);
        return -1;
    }
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
        bytes_written = fwrite(buffer, 1, bytes_read, dest_file);
        if (bytes_written != bytes_read) {
            perror("Erreur d'écriture dans le fichier destination");
            fclose(source_file);
            fclose(dest_file);
            return -1;
        }
    }
    if (ferror(source_file)) {
        perror("Erreur lors de la lecture du fichier source");
        fclose(source_file);
        fclose(dest_file);
        return -1;
    }
    fclose(source_file);
    fclose(dest_file);

    return 0;
}
int copy_files_to_directory(char *files[], int file_count, const char *directory) {
    char dest_path[1024];
    int i;
    
    for (i = 0; i < file_count; i++) {
        snprintf(dest_path, sizeof(dest_path), "%s/%s", directory, strrchr(files[i], '/') ? strrchr(files[i], '/') + 1 : files[i]);
       
        if (copy_file(files[i], dest_path) == -1) {
            return -1;
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s SOURCE... DEST ou %s SOURCE DEST\n", argv[0], argv[0]);
        return 1;
    }
    if (argc == 3) {
        if (copy_file(argv[1], argv[2]) == -1) {
            return 1;
        }
    }
    else {
        const char *directory = argv[argc - 1];
        if (copy_files_to_directory(argv + 1, argc - 2, directory) == -1) {
            return 1;
        }
    }

    return 0;
}

