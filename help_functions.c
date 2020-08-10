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
/**
 * _strcpy - function
 * @dest: pointer
 * @src: pinter
 * Return: diferent zero
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i] + '\0';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
* _strcat -  function to concatenate two strings
* @dest: first string
* @src: second string
* Return: no zero
*/
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	return (dest);
}
/**
* _strcmp -  function to compare two strings
* @s1: first string
* @s2: second string
* Return: no zero
*/
int _strcmp(char *s1, char *s2)
{
	int i = 0, j = 0;

	while ((s1[i] && s2[j]) && s1[i])
		i++, j++;
	if (s1[i] == s2[j])
		return (0);
	else
		return (s1[i] - s2[j]);
	return (0);
}
/**
 * _strdup - returns a pointer to a newly allocated space in memory
 *           which contains a copy of the string given as a parameter.
 * @str: string to copy
 * Return: Pointer to newly allocated space in memory
 */
char *_strdup(char *str)
{
	char *s;
	unsigned int i, j;

	if (str == NULL)
		return (NULL);
	j = 0;
	while (str[j] != '\0')
	{
		j++;
	}
	s = malloc(sizeof(char) * (j + 1));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (j > 0)
	{
		s[i] = str[i];
		i++;
		j--;
	}
	return (s);
}
