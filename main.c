#include "shell.h"

/**
 * main - Entry point of shell.
 * @ac: argument count.
 * @argv: argument variable.
 * @env: NULL terminated array of strings.
 *
 * Return: 0 on success.
 */

int main(__attribute__((unused))int ac, char **argv, char **env)
{
	char *lineptr = NULL, *line_cpy = NULL, *token;
	size_t n = 0;
	ssize_t get;
	const char *delim = " \n";
	int ntok = 0, i;

	while (1)
	{
		get = getline(&lineptr, &n, stdin);

		if (get == -1)
		{
			free(lineptr);
			exit(EXIT_SUCCESS);
		}
		line_cpy = malloc(sizeof(char) * get);
		if (line_cpy == NULL)
			return (-1);
		str_cpy(line_cpy, lineptr);
		token = strtok(lineptr, delim);
		while (token != NULL)
		{
			ntok++;
			token = strtok(NULL, delim);
		}
		ntok++;
		argv = malloc(sizeof(char *) * ntok);
		token = strtok(line_cpy, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char *) * _strlen(token));
			str_cpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		execute_command(argv, env);
	}

	free(lineptr);
	free(line_cpy);
	return (0);
}
