#include "shell.h"

/**
  * _freetok - frees a given array of tokens.
  * @tokArray: array of tokens to be freed.
  *
  */

void _freetok(char **tokArray)
{
	char **cpyArray = tokArray;

	if (tokArray)
	{
		while (*tokArray)
			free(*tokArray++);

		free(cpyArray);
	}
}
