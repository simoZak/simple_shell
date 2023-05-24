#ifndef SHELL_H
#define SHELL_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/wait.h>

void execute_command(char **cmd, char **env);
char *no_newLineChar(char *string);
int _putchar(char c);
void printprompt(void);
char *removeSpaces(char *str);

#endif
