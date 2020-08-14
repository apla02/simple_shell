#include "holberton.h"
int counter_words(char *string);
int _execute(char **argv);
void _analize(char *str)
{
	char *tokenizar;
	int i = 1;
	int n = counter_words(str);
	char **argv = malloc(sizeof(char *) * (n + 1));
	*argv = strtok(str, " \n\t");
	//_which(str);
	//return;

	while (i <= n)
	{
		argv[i] = strtok(NULL, " \n\t");
		i++;

	}
	argv[i] = NULL;
	_execute(argv);
	free(argv);
}
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
