#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * INThandler - function to handle the signal int
 * @sig: signal
 * Return: none
 */
void INThandler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}
/**
 * main - function to prompt the simple shell
 * void: --
 * Return: zero
 */
int main(void)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t read;
	
	write(STDIN_FILENO, "$ ", 2);
	signal(SIGINT, INThandler);
	while ((read = getline(&line, &n, stdin)) != EOF)/* lee la linea*/
	{
		if (*line == '\n')
		{
			write(STDIN_FILENO, "$ ", 2);
			continue;
		}
		char **argv = _analize(line);

		if ((check_exit(argv[0])) == 0)
		{
			free(line);
			free(argv);
			exit(EXIT_SUCCESS);
		}

		_execute(argv);
		write(STDIN_FILENO, "$ ", 2);
		free(argv);
		free(line);
		line = NULL;
		n = 0;
	}
	if (read == EOF)
	{
		free(line);
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
