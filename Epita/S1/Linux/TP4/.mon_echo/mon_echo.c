#include <stdio.h>
#include <string.h>

int is_valid_option(const char *arg)
{
    if (arg[0] != '-' || arg[1] == '\0')
        return 0;

    for (int i = 1; arg[i]; i++)
    {
        if (arg[i] != 'n' && arg[i] != 'E' && arg[i] != 'e')
            return 0;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    int saut = 1;
    int debut = 1;
    while (debut < argc && is_valid_option(argv[debut]))
    {
        for (int j = 1; argv[debut][j]; j++)
        {
            if (argv[debut][j] == 'n')
                saut = 0;
        }
        debut++;
    }
    for (int i = debut; i < argc; i++)
    {
        printf("%s", argv[i]);
        if (i + 1 < argc)
            printf(" ");
    }

    if (saut)
        printf("\n");

    return 0;
}
