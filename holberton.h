#ifndef _HOLBERTON_H
#define _HOLBERTON_H
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_which(char *s);
char *_getenv(const char *name);
void _analize(char *str);
extern char **environ;
void _envprint();
int _match(char *str1, char *line);
#endif
