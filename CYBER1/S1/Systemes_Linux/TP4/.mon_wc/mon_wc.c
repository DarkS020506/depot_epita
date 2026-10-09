#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#define BUF_SIZE 4096

long total_lines = 0;
long total_words = 0;
long total_bytes = 0;

int is_space(char c)
{
    return (c == ' ' || c == '\n' || c == '\t');
}

void wc_fd(int fd, long *lines, long *words, long *bytes)
{
    char buf[BUF_SIZE];
    ssize_t n;
    int in_word = 0;

    while ((n = read(fd, buf, BUF_SIZE)) > 0)
    {
        *bytes += n;

        for (ssize_t i = 0; i < n; i++)
        {
            if (buf[i] == '\n')
                (*lines)++;

            if (is_space(buf[i]))
            {
                in_word = 0;
            }
            else if (!in_word)
            {
                in_word = 1;
                (*words)++;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int fd;
    long lines, words, bytes;
    int files = 0;
    total_lines = 0;
    total_words = 0;
    total_bytes = 0;

    if (argc == 1)
    {
        wc_fd(STDIN_FILENO, &total_lines, &total_words, &total_bytes);
        printf("%7ld %7ld %7ld\n",
               total_lines, total_words, total_bytes);
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        lines = words = bytes = 0;

        if (argv[i][0] == '-' && argv[i][1] == '\0')
        {
            fd = STDIN_FILENO;
        }
        else
        {
            fd = open(argv[i], O_RDONLY);
            if (fd < 0)
            {
                perror(argv[i]);
                continue;
            }
        }

        wc_fd(fd, &lines, &words, &bytes);

        if (fd != STDIN_FILENO)
            close(fd);
        printf("%7ld %7ld %7ld %s\n",
               lines, words, bytes, argv[i]);

        total_lines += lines;
        total_words += words;
        total_bytes += bytes;
        files++;
    }
    if (files > 1)
    {
        printf("%7ld %7ld %7ld total\n",
               total_lines, total_words, total_bytes);
    }

    return 0;
}
