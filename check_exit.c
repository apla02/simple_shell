#include "holberton.h"
/**
 */
int check_exit(char *str)
{
    if (!(_strcmp("exit", str)))
        return (0); /*success*/
    return (1);/*failure*/
}