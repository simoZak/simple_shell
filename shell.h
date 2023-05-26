#ifndef SHELL_H
#define SHELL_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/wait.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>

extern char **environ;

void execute_command(char **cmd, char **env);
char *no_newLineChar(char *string);
int _putchar(char c);
void printprompt(void);
char *removeSpaces(char *str);
int _strlen(const char *s);
char *str_cpy(char *cpy, char *org);
int str_cmp(char *a, char *b);
char *_strdup(char *s);
char *get_environ(const char *name);
char *get_origin(char *cmd);
int strn_cmp(const char *s1, const char *s2, size_t len);
char *str_cat(char *dest, char *src);
void _freetok(char **tokArray);

#endif
