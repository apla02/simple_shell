#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * main - function to prompt the simple shell
 * void: --
 * Return: zero
 */
int _match(char *str1, char *line);
int main(void)
{
	char *line = NULL;
	size_t n = 0; /*tamaño del buffer*/
	ssize_t read;

	if (isatty(STDIN_FILENO))
		write(STDIN_FILENO, "$ ", 2);
	while ((read = getline(&line, &n, stdin)) != EOF)
	{
		//printf("%s", line);
		if(!(_match("exit", line)))
		{
			if ((line[4] == ' ' || line[4] == '\n' || line[4] == '\t'))
			{
				free(line);
				exit(EXIT_SUCCESS);
			}
			else
			{
				write(STDIN_FILENO, "No founded\n", 11);
			}
		}
		else if(!(_match("env", line)))
		{
			if ((line[3] == ' ' || line[3] == '\n' || line[3] == '\t') && read <= 5)
			{
				_envprint(environ);
			}
			else
			{
				write(STDIN_FILENO, line, read - 1);
				write(STDIN_FILENO, ": command not found\n", 21);
			}
		}
		else
		_analize(line);
		write(1, "$ ", 2);
		free(line);
		line = NULL, n = 0;
	}
	return (0);
}
