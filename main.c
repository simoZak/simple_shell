#include "shell.h"

/**
 * main - Entry point of shell.
 * @ac: argument count.
 * @argv: argument variable.
 *
 * Return: 0 on success.
 */

int main(__attribute__((unused))int ac, __attribute__((unused))char **argv)
{
	char *lineptr;
	size_t n = 0;
	ssize_t get;
	char *myArray[2];

    /* create an infinite loop */
	while (1)
	{
		printprompt();
		get = getline(&lineptr, &n, stdin);
		if (get == -1)
		{
			perror("Error");
			return (-1);
		}

		no_newLineChar(lineptr);
		myArray[0] = lineptr;
		myArray[1] = NULL;
		execute_command(myArray);
	}
	free(lineptr);

	return (0);
}
