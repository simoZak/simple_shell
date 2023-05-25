#include "shell.h"

/**
 * _strlen - returns the length of a string
 *
 * @s: input string
 * Return:  length of string
 */

int _strlen(const char *s)
{
	int a;

	for (a = 0; s[a] != '\0'; a++)
	{

	}
	return (a);
}


/**
 * str_cpy - copy the string pointed to by org inluding the null byte
 * to the buffer pointed to by cpy.
 * @cpy: desired copy of string.
 * @org: original string.
 * Return: pointer to desired copy of string.
 */
char *str_cpy(char *cpy, char *org)
{
	int b = 0;

	while (org[b])
	{
		cpy[b] = org[b];
		b++;
	}
	cpy[b] = '\0';

	return (cpy);
}

/**
  * str_cmp - Compares two strings
  * @a: The first string
  * @b: The second string
  *
  * Return: integer value.
  */
int str_cmp(char *a, char *b)
{
	int la = 0, lb = 0, breadth = 0, width = 0, lvl = 0;

	la = _strlen(a);
	lb = _strlen(b);

	if (la <= lb)
		width = la;
	else
		width = lb;

	while (breadth <= width)
	{
		if (a[breadth] == b[breadth])
		{
			breadth++;
			continue;
		}
		else
		{
			lvl = a[breadth] - b[breadth];
			break;
		}

		breadth++;
	}

	return (lvl);
}

/**
 * _strdup - returns a pointer to a new string which is a duplicate of s.
 * @s: The required string to be duplicated.
 * Return: pointer to the duplicated string.
 * or NULL if str = NULL or if insufficient memory was available.
 */
char *_strdup(char *s)
{
	char *dup;

	if (s == NULL)
		return (NULL);
	dup = malloc(sizeof(char) * (_strlen(s) + 1));
	if (dup == NULL)
		return (NULL);
	return (str_cpy(dup, s));
}

/**
 * *str_cat - concatenates two strings.
 * @dest: destination.
 * @src: source.
 * Return: pointer to the resulting string dest.
 */
char *str_cat(char *dest, char *src)
{
	int i, j;
	char *ptr = dest;

	if (src == NULL)
		return (ptr);
	for (i = 0; dest[i] != '\0'; i++)
	;
	for (j = 0; src[j] != '\0'; i++, j++)
		dest[i] = src[j];
	dest[i] = '\0';

	return (ptr);
}
