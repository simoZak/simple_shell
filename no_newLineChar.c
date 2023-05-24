#include "shell.h"

/**
 * no_newLineChar - removes the new line terminator '\n' from a string.
 * @string: The string containing '\n' to be removed.
 *
 * Return: The desired string without '\n'.
 */

char *no_newLineChar(char *string)
{
	int s = 0, r = 0;

	while (string[r])
	{
		if (string[r] == ' ')
		{
			string[r] = string[r + 1];
		}
		r++;
	}

	while (string[s])
	{
		if (string[s] == '\n')
		{
			string[s] = '\0';
		}
		if (string[s] == ' ')
		{
			string[s] = '\0';
		}
		s++;
	}

	return (string);
}
