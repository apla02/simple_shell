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
* @s1: first string
* @s2: second string
* Return: no zero
*/
int _strcmp(char *s1, char *s2)
{
	int i = 0, j = 0;

	while ((s1[i] && s2[j]) && s1[i] == s2[j])
		i++, j++;
	if (s1[i] == s2[j])
		return (0);
	else
		return (s1[i] - s2[j]);
	return (0);
}

/**
* _str_concat -  function to concatenate two strings
* @s1: first string
* @s2: second string
* Return: no zero
*/
char *_str_concat(char *s1, char *s2)
{
	char *concatenar;
	unsigned int i, j, cp, r, final_leng;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i]; i++)
		;
	for (j = 0; s2[j]; j++)
		;
	final_leng = i + j + 1;

	concatenar = malloc(final_leng * sizeof(char));

	if (concatenar == NULL)
		return (NULL);

	for (cp = 0; cp < i; cp++)
	{
		concatenar[cp] = s1[cp];
	}
	for (r = 0; r < j; cp++, r++)
	{
		concatenar[cp] = s2[r];
	}

	return (concatenar);
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
