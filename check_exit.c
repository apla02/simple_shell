#include "holberton.h"
/**
 * check_exit - function to check the fn exit
 * @str: argv[0];
 * Return: zero of success
 */
int check_exit(char *str)
{
	if (!(_strcmp("exit", str)))
		return (0); /*success*/
	return (1);/*failure*/
}
