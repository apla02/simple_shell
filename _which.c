#include "holberton.h"
/**
 * _which- function to look for a path of a arg within path var
 * @arg: arg where _which is going to look the path
 * Return: the path of the arg
 */
char *_which(char *arg)
{
	struct stat exist;
	int i = 1;
	char *get_path = getenv("PATH");
	char slash[] = {"/"};
	char *get_path1 = _strdup(get_path);
	int num_paths = counter_paths(get_path1);
	char **buffer = malloc(sizeof(char *) * num_paths);
	char *extension, *whole_path, *whole_path1;

	*buffer = strtok(get_path1, ":");
	while (i < num_paths)
	{
		buffer[i] = strtok(NULL, ":");
		i++;
	}
	extension = _strcat(slash, arg);/* está funcionando*/
	i = 0;
	while (buffer[i])
	{
		/*printf("%s\n", buffer[i]);*/
		whole_path = _strcat(buffer[i], extension);
		/*printf("%s\n", whole_path);*/
		if ((stat(whole_path, &exist)) == 0)
		{
			whole_path1 = _strdup(whole_path);
			printf("%s\n", whole_path1);
			return (whole_path1);
		}
		i++;
	}
return (NULL);
}
/**
 * counter_paths- function to counts the numbers of paths
 * @string: string that contains the paths
 * Return: numbers of paths including the null
 */
int counter_paths(char *string)
{
	int state = 1;
	int counting = 0;

	while (*string)
	{
		if (*string == ':')
			state = 1;
		else
			if (state == 1)
				counting++, state = 0;
				string++;
	}
	return (counting + 1);
}

