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

	child_pid = fork();

	if (child_pid == 0)
	{
		execve(cmd[0], cmd, env);
		if (execve(cmd[0], cmd, env) == -1)
			perror("./hsh");
	}
	else
	{
		wait(&status);
	}
}
