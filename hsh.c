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
	struct stat exist;
	size_t n = 0;
	ssize_t read;

	if (isatty(STDIN_FILENO))
		write(STDIN_FILENO, "$ ", 2);
	signal(SIGINT, INThandler);
	while ((read = getline(&line, &n, stdin)) != EOF)/* lee la linea*/
	{
		char **argv = _analize(line);

		argv[0] = _which(argv[0]);
		if (!(_match("exit", argv[0])))
		{
			free(argv);
			exit(EXIT_SUCCESS);
		}
		else if (!(_match("env", argv[0])))/*error cuando ingreso enva o envh también lo lee*, arreglar función match*/
			_envprint(environ);
		else if ((stat(argv[0], &exist)) == 0)
			_execute(argv);
		else
			perror("command not found\n");/*revisar el  "" error de stdoutput*/
	write(STDIN_FILENO, "$ ", 2);
	free(argv);
	free(line);
	line = NULL, n = 0;
	}
	return (0);
}
