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
#include <signal.h>
#include <linux/limits.h>
#include <fcntl.h>

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


void read_file(char *filename, char **argv);
void prompt(void);
void signal_to_handel(int sig);
char *_getline(void);
int history(char *input);
char **parse_cmd(char *cmd);
void  exit_bul(char **cmd, char *input, char **argv, int c);
int check_cmd(char **tokens, char *line, int count, char **argv);
void free_all(char **input, char *line);
int _strcmp(char *s1, char *s2);
int check_builtin(char **cmd);
int handle_builtin(char **cmd, int er);

typedef struct  bulltin
{
	char *command;
	int (*fun)(char **line, int er);
} bul_t;

#endif
