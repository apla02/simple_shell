#include "holberton.h"
/**
 * _envprint - print the environment
 * @env: extern var environ
 * Return : none
 */
void _envprint(char **env)
{
	int i = 0, len;

	env = environ;
	while (env[i])
	{
		length = strlen(env[i]);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
		++i;
	}
}
