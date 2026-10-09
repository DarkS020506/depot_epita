#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int n = argc - 1;
    if (n == 0)
    {
        fprintf(stderr, "mon_test: pas assez d'arguments\n");
        return 2;
    }
    if (n == 1)
    {
        return (argv[1][0] != '\0') ? 0 : 1;
    }
    if (n == 2)
    {
        if (strcmp(argv[1], "-n") == 0)
            return (argv[2][0] != '\0') ? 0 : 1;

        if (strcmp(argv[1], "-z") == 0)
            return (argv[2][0] == '\0') ? 0 : 1;

        fprintf(stderr, "mon_test: %s\n", argv[1]);
        return 2;
    }
    if (n == 3)
    {
        if (strcmp(argv[2], "=") == 0)
            return (strcmp(argv[1], argv[3]) == 0) ? 0 : 1;

        if (strcmp(argv[2], "!=") == 0)
            return (strcmp(argv[1], argv[3]) != 0) ? 0 : 1;

        if (strcmp(argv[2], "<") == 0)
            return (strcmp(argv[1], argv[3]) < 0) ? 0 : 1;

        if (strcmp(argv[2], ">") == 0)
            return (strcmp(argv[1], argv[3]) > 0) ? 0 : 1;

        fprintf(stderr, "mon_test: %s\n", argv[2]);
        return 2;
    }
    fprintf(stderr, "mon_test: trop d'arguments\n");
    return 2;
}
