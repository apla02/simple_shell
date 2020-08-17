#include "holberton.h"
/**
 * _execute - functio to execute the arg
 * @argv: arg to execute
 * Return: zero if sucess
 */
int _execute(char **argv)
{
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
				perror("Error:");
				free(argv[0]);
				free(argv);
				exit(EXIT_FAILURE);
			}
			else if (!(_strcmp("env", argv[0])))
			{
				_envprint(environ);
			}
			else if ((stat(argv[0], &exist)) == 0)
				execve(*argv, argv, NULL);
			else
				perror("error");
				exit(EXIT_SUCCESS);
		}
		else
			wait(&status);
	return (0);
}
