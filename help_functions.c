#include "holberton.h"
/**
 * _strlen - function to return the length a string
 * @s: string
 * Return: str
 */
int _strlen(char *s)
{
	int len;

	for (len = 0; s[len]; len++)
	;
	return (len);
}

#include "holberton.h"
/**
* _strcmp -  function to compare two strings
* @str1: first string
* @str2: second string
* Return: no zero
*/
int _strcmp(char *str1, char *str2)
{
	int i = 0, j = 0;

	while ((str1[i] && str2[j]) && str1[i] == str2[j])
		i++, j++;
	if (str1[i] == str2[j])
		return (0);
	else
		return (str1[i] - str2[j]);
	return (0);
}

/**
* _str_concat -  function to concatatenate two strings
* @str1: first string
* @str2: second string
* Return: no zero
*/
char *_str_concat(char *str1, char *str2)
{
	char *concat;
	unsigned int i = 0, j = 0, len = 0, index = 0;

	if (str1 == NULL)
		str1 = NULL;
	if (str2 == NULL)
		str2 = NULL;
	i = _strlen(str1);
	j = _strlen(str2);
	len = i + j + 1;
	concat = malloc(sizeof(char) * len);
	if (concat == NULL)
		return (NULL);
	for (index = 0; index < i; index++)
		concat[index] = str1[index];
	for (index = 0; index <= j; i++, index++)
		concat[i] = str2[index];

	return (concat);
	free(concat);
}
/**
 * _strdup - returns a pointer to the new copy of string allocated with malloc
 * @str: string to copy
 * Return: Pointer to newly allocated space in memory
 */
char *_strdup(char *str)
{
	unsigned int i, j;
	char *dest;

	if (str == NULL)
	return (NULL);

	for (i = 0; *(str + i); i++)
		;
	dest = malloc(sizeof(char) * (i + 1));

	if (dest == NULL)
	return (NULL);

	for (j = 0; j <= i ; j++)
		*(dest + j) = *(str + j);
	return (dest);
}
/**
 * _match - compare to the new copy of string allocated with malloc
 * @str1: string 1 to compare
 * @line: str 2 to compare
 * Return: Pointer to newly allocated space in memory
 */
int _match(char *str1, char *line)
{
	while (*str1)
	{
		if (*str1 == *line)
			str1++, line++;
		else
			break;
	}
	if (*str1)
		return (1);
	else
		return (0);
}
