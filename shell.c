#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(void)
{
    char *line = NULL;
    size_t n = 0; /*tamaño del buffer*/
    ssize_t read;
    int isat = isatty(STDIN_FILENO);

    if (isat == 1)
        write (1,"$ ", 2);
    while ((read =getline(&line, &n, stdin )) != EOF)
    {
        _analize(line);
        write (1,"$ ", 2);
        free(line);
        line = NULL, n = 0;
    }
    return (0);
}
