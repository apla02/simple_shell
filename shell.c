#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * main - function to prompt the simple shell
 * void: --
 * Return: zero
 */
int main(void)
{
	char *line = NULL;
	size_t n = 0; /*tamaño del buffer*/
	ssize_t read;

	if (isatty(STDIN_FILENO))
		write(STDIN_FILENO, "$ ", 2);
	while ((read = getline(&line, &n, stdin)) != EOF)
	{
		if (read == -1)
		{
			exit(EXIT_FAILURE);
		}
		_analize(line);
		write(1, "$ ", 2);
		free(line);
		line = NULL, n = 0;
	}
	return (0);
}
