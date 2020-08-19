#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_str_concat(char *s1, char *s2);
char *_strdup(char *str);
char *_which(char *s);
char *_getenv(const char *name);
extern char **environ;
int check_exit(char *str);
char **_analize(char *str);
int _execute(char **argv);
int counter_paths(char *string);
int counter_words(char *string);
void error_message(char **argv, int n);
#endif
