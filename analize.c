#include "holberton.h"
/**
 * _analize - function to split a str
 * @str: string to split
 * Return: str
 */
char **_analize(char *str)
{
	int i = 1;
	int n = counter_words(str);
	char **argv = malloc(sizeof(char *) * (n + 1));

	if (argv == NULL)
		return (NULL);
	*argv = strtok(str, " \n\t");

	while (i < n)
	{
		argv[i] = strtok(NULL, " \n\t");
		i++;

	}
	argv[i] = NULL;
	return (argv);
}

/**
 * counter_words - function count the words of a string
 * @string: string to count the words
 * Return: number of words
 */
int counter_words(char *string)
{
	int state = 1;
	int counting = 0;

	while (*string)
	{
		if (*string == '\n' || *string == '\t' || *string == ' ')
			state = 1;
		else
			if (state == 1)
				counting++, state = 0;
		string++;
	}
	return (counting);
}
