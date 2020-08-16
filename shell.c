#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * INThandler - function to handle the signal int
 * sig: signal
 * Return: none
 */
void INThandler(int sig)
{
	(void)sig;
	//write(STDOUT_FILENO, "\n$ ", 3);
}
/**
 * main - function to prompt the simple shell
 * void: --
 * Return: zero
 */
int main(void)
{
	char *line = NULL;
	struct stat exist;
	char command_exit[] = {"exit"};
	size_t n = 0; /*tamaño del buffer*/
	ssize_t read;

	if (isatty(STDIN_FILENO))
		write(STDIN_FILENO, "$ ", 2);
	signal(SIGINT, INThandler);
	while ((read = getline(&line, &n, stdin)) != EOF)/* lee la linea*/
	{
		if(!(_match("env", line)))
		{
			if ((line[3] == ' ' || line[3] == '\n' || line[3] == '\t') && read <= 5)
				_envprint(environ);
			else
			{
				write(STDIN_FILENO, line, read - 1);
				write(STDIN_FILENO, ": command not found\n", 21);
			}
		}
		else
		{
			char **argv = _analize(line);
			argv[0] = _which(argv[0]);
			//printf("%s\n", *argv);
			if ((stat(argv[0], &exist)) == 0)
				_execute(argv);
			else
			{
				if (argv[0] == command_exit && !argv[1])
				{
					free(argv);
					exit(EXIT_SUCCESS);
				}
				else
				{
					write(STDIN_FILENO, line, read - 1);
					write(STDIN_FILENO, ": command not found\n", 21);
				}
							
			}
				
			free(argv);
			//free(whole_path1);
		}
		write(1, "$ ", 2);
		free(line);
		line = NULL, n = 0;
	}
	return (0);
}

