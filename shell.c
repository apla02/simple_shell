#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * main - function to prompt the simple shell
 * void: --
 * Return: zero
 */
int _match(char *str1, char *line);
int main(void)
{
	char *line = NULL;
	size_t n = 0; /*tamaño del buffer*/
	ssize_t read;

	if (isatty(STDIN_FILENO))
		write(STDIN_FILENO, "$ ", 2);
	while ((read = getline(&line, &n, stdin)) != EOF)
	{
		printf("%s", line);
		if(!(_match("exit", line)))
		{
			if (line[4] == ' ' || line[4] == '\n' || line[4] == '\t')
			{
				free(line);
				exit(0);/* looking for the right number for to exit from the terminal*/
			}
			else
			{
				write(STDIN_FILENO, "No founded\n", 11);
			}
		}
		else if(!(_match("env", line)))
		{
			if (line[3] == ' ' || line[3] == '\n' || line[3] == '\t')
			{
				_envprint(environ);
			}
			else
			{

				write(STDIN_FILENO, "No founded\n", 11);
			}
		}
		else
		_analize(line);
		write(1, "$ ", 2);
		free(line);
		line = NULL, n = 0;
	}
	return (0);
}
int _match(char *str1, char *line)
{
    while (*str1)
    {
      
      if(*str1 == *line)
        str1++, line++;
      else
        break;
    }
    if (*str1)
      return (1);
    else  
      return(0);
}