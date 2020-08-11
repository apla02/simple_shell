#include "holberton.h"
/**
 * _which : function to look for a path of a command within path var
 * @command: command where _which is going to look the path
 * Return: the path of the command
 */
char *_which(char *command)
{
    struct stat *exist;
    int i = 0;
    char *get_path = getenv("PATH");
    char *get_path1 = _strdup(get_path);
    char *delim = ":";
    char *tokenizador = strtok(get_path1, delim);
    char *extension = "/";
    char *buffer[120];
    char *concat1, *whole_path;

    while (tokenizador)
    {
        buffer[i] = tokenizador;
		tokenizador = strtok(NULL, delim);
        i++;
    }
    free (get_path1);/** revisar si se libera acá*/
    buffer[i] == NULL;
    concat1 = _strcat(extension, command);

    i = 0;
    while (buffer)
    {
        whole_path = _strcat(buffer[i], concat1);/** concateno cada token de path con el slash y el nombre del comando**/
        exist = stat(whole_path, &exist); /*valido con stat si la ruta existe, si existe  es igual a cero y me retorna esa ruta*/

        if (exist == 0)
            return (whole_path);
            exit(EXIT_SUCCESS);/* si sería acá*/
        i++;
    }
    return (0);
}
