#include "shell.h"

/**
 * main - Entry point of shell.
 * @ac: argument count.
 * @argv: argument variable.
 * @env: NULL terminated array of strings.
 *
 * Return: 0 on success.
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *input, **cmd;
	int iter = 0, etat = 1, var = 0;

	if (argv[1] != NULL)
		read_file(argv[1], argv);
	signal(SIGINT, signal_to_handel);
	while (etat)
	{
		iter++;
		if (isatty(STDIN_FILENO))
			prompt();
		input = _getline();
		if (input[0] == '\0')
		{
			continue;
		}
		history(input);
		cmd = parse_cmd(input);
		if (_strcmp(cmd[0], "exit") == 0)
		{
			exit_bul(cmd, input, argv, iter);
		}
		else if (check_builtin(cmd) == 0)
		{
			var = handle_builtin(cmd, var);
			free_all(cmd, input);
			continue;
		}
		else
		{
			var = check_cmd(cmd, input, iter, argv);

		}
		free_all(cmd, input);
	}
	return (etat);
}

int check_builtin(char **cmd)
{
	bul_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;
		if (*cmd == NULL)
	{
		return (-1);
	}

	while ((fun + i)->command)
	{
		if (_strcmp(cmd[0], (fun + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}

void creat_envi(char **envi)
{
	int i;

	for (i = 0; environ[i]; i++)
		envi[i] = _strdup(environ[i]);
	envi[i] = NULL;
}
