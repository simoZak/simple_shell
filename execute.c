#include "shell.h"

/**
 * execute_command - Executes a given command if found else print error msg.
 *
 * @cmd: array containing desired command to be executed.
 */

void execute_command(char **cmd)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == 0)
	{
		execve(cmd[0], cmd, NULL);
		perror("Error");
	}
	else
	{
		wait(&status);
	}
}