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
int _strcmp(char *s1, char *s2);
char *_str_concat(char *s1, char *s2);
char *_strdup(char *str);
char *_which(char *s);
char *_getenv(const char *name);
int check_exit(char *str);
char **_analize(char *str);
int _execute(char **argv);
extern char **environ;
void _envprint(char **env);
int _match(char *str1, char *line);
int counter_paths(char *string);
int counter_words(char *string);
#endif
