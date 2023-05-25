#include "shell.h"

/**
  * get_environ - Gets an environment variable
  * @name: The variable to find in the system environment
  *
  * Return: The content of the environment variable
  */
char *get_environ(const char *name)
{
	int a = 0;
	char *env_array = NULL;

	while (environ[a])
	{
		if (strn_cmp(name, environ[a], _strlen(name)) == 0)
		{
			env_array = _strdup(environ[a]);
			while (*env_array != '=')
				env_array++;

			++env_array;
			return (env_array);
		}
		a++;
	}

	return (NULL);
}
