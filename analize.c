#include "holberton.h"
int counter_words(char *String);
int _fork(char **argv);
void _analize(char *str)
{
	char *tokenizar;
	int i = 1;
	int n = counter_words(str);
	char **argv = malloc(sizeof(char*) * (n + 1));
	*argv = strtok(str, " \n\t");

	while ( i <= n )
	{
		argv[i] = strtok(NULL, " \n\t");
		i++;     
	}
	argv[i] = NULL;

	i = 0;
	_fork(argv);
	free (argv);
}
int counter_words(char *String)
{
	int State = 1;  
	int Counter_Word = 0;
	while (*String)
	{
		if (*String == '\n' || *String == '\t' || *String == ' ')
			State = 1;
		else
			if (State == 1)
				Counter_Word++, State = 0;
				String++;
		} 
	return (Counter_Word);
}
int _fork(char **argv)
{
	int status;
	pid_t child_pid = fork();
		
	if (child_pid == -1) {
			perror("Error:");
	}
	/* The child process*/
	else if (child_pid == 0)
	{
		execve(*argv, argv, NULL);
	}
	else 
		wait(&status);
 
	return 0;
}
