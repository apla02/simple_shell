#include "holberton.h"
/**
 * _putchar - print a character
 * @c:character
 * Return: zero
*/
int _putchar(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}
/**
 * build_error_message -fn to display the error message
 * @argv: pointer of arrays
 * @n:counts the errors
 * Return: none
*/
void build_error_message(char **argv, int n)
{
	int mul, numlength, copy;

	write(STDERR_FILENO, "hsh", 3);
	write(STDERR_FILENO, ": ", 2);

	copy = n;
	mul = 1;
	numlength = 1;
	while (copy >= 10)
	{
		copy /= 10;
		mul *= 10;
		++numlength;
	}
	while (numlength > 1)
	{
		if ((n / mul) < 10)
			_putchar((n / mul + '0'));
		else
			_putchar((n / mul) % 10 + '0');
		--numlength;
		mul /= 10;
	}
	_putchar(n % 10 + '0');
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": not found\n", 12);
}

