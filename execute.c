#include "shell.h"

/**
 * execute_command - Executes a given command if found else print error msg.
 *
 * @cmd: array containing desired command to be executed.
 * @env: a NULL terminated array.
 */

void execute_command(char **cmd, char **env)
{
	pid_t child_pid;
	int status;
	char *cd = NULL, *acd = NULL;

	child_pid = fork();

	if (child_pid == 0)
	{
		cd = cmd[0];
		acd = get_origin(cd);
		execve(acd, cmd, env);
		if (execve(cmd[0], cmd, env) == -1)
		{
			perror("./hsh");
			printprompt();
		}
		printprompt();
	}
	else
	{
		wait(&status);
	}
}
