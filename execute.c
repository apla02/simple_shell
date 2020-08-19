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
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			argv[0] = _which(argv[0]);
			if (argv == NULL)
			{
				free(argv[0]);
				free(argv);
				exit(EXIT_SUCCESS);
			}
			else if ((stat(argv[0], &exist)) == 0)
			{
				if ((execve(*argv, argv, environ)) == -1)
				{
					free(argv);
					exit(EXIT_FAILURE);
				}
				exit(EXIT_SUCCESS);
			}
			else
			{
				error_message(argv, n);
				exit(127);
			}
		}
		else
			wait(&status);
	return (0);
}
