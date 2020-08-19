#include "holberton.h"
/**
 * _execute - functio to execute the arg
 * @argv: arg to execute
 * Return: zero if sucess
 */
int _execute(char **argv)
{
	int n = 1;
	int status;
	pid_t child_pid = fork();
	struct stat exist;

	if (child_pid == -1)
	{
		perror("Error: ");
	}
	else if (child_pid == 0)
	{
		argv[0] = _which(argv[0]);
		if (argv == NULL)
		{
			free(argv[0]);
			free(argv);
		}
		else if ((stat(argv[0], &exist)) == 0 /*&& exist.st_mode & S_IXUSR*/)
		{
			if ((execve(*argv, argv, environ)) == -1)
			{
				free(argv[0]);
				free(argv);
				perror("Error ");
			}
			else
				free(argv[0]);
				free(argv);
		}
		error_message(argv, n);
	}
	else
		wait(&status);
	return (0);
}
