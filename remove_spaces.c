#include "shell.h"

/**
 * removeSpaces - removes leading and trailing whitespacrs from a string.
 *
 * @str: desrired string with leading and trailing spaces to be removed.
 *
 * Return: desrired string without leading or trailing spaces.
 */

char *removeSpaces(char *str)
{
	int i, j;

	for (i = 0; str[i] == ' ' || str[i] == '\t'; i++)
		;

	for (j = 0; str[i]; i++)
	{
		str[j++] = str[i];
	}
	str[j] = '\0';

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && str[i] != '\t')
			j = i;
	}
	str[j + 1] = '\0';

	return (str);
}
