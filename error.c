#include "holberton.h"
/**
 * error -fn to display the error message
 * @message: message to display in each error
 * Return: none
*/
void error(char **argv, char *message)
{
	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, message, _strlen(message));
	exit(127);
}
