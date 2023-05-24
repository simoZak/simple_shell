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
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t get;



    /* create an infinite loop */
	while (1)
	{
		get = getline(&lineptr, &n, stdin);
		if (!lineptr)
		{
			free(lineptr);
			exit(EXIT_SUCCESS);
		}


		if (get == -1)
		{
			free(lineptr);
			exit(EXIT_SUCCESS);
		}

		no_newLineChar(lineptr);
		removeSpaces(lineptr);

		if (lineptr == NULL)
			return (-1);

		argv[0] = lineptr;
		argv[1] = NULL;
		execute_command(argv, env);
	}
	free(lineptr);

	return (0);
}
