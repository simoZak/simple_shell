#include "shell.h"

/**
 * get_origin - get the path of a variable.
 *
 * @cmd: command
 * Return: character
 */
char *get_origin(char *cmd)
{
	char *path, *path_copy, *path_token, *file_path;
	int cmd_len, directory_length;
	struct stat buffer;

	path = get_environ("PATH");

	if (path)
	{
		path_copy = _strdup(path);
		cmd_len = _strlen(cmd);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			directory_length = strlen(path_token);
			file_path = malloc(cmd_len + directory_length + 2);
			str_cpy(file_path, path_token);
			str_cat(file_path, "/");
			str_cat(file_path, cmd);
			str_cat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(cmd, &buffer) == 0)
		{
			return (cmd);
		}
		return (NULL);
	}
	return (NULL);
}
