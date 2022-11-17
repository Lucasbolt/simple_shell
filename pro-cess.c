#include "main.h"


/**
 * startProcess - forks a process
 * @args: arguments
 * @front: pointer to @args
 * Return: 0 on success
 */
int startProcess(char **args, char **front)
{
	int ret = 1;
	pid_t pid;

	pid = fork();

	if (pid < 0)
		return (1);
	else if (pid == 0)
	{
		ret = execve(args[0], args, environ);
		free_env();
		freemem(args, front);
	}
	else
	{
		wait(NULL);
	}
	if (ret == -1)
		return (ret);
	return (0);
}

/**
 * pathProcess - starts a child process to execute commands
 * @dir: path to command
 * @args: command arguments
 * @front: pointer to @args
 * Return: 0 on success
 */
int pathProcess(char *dir, char **args, char **front)
{
	int ret = 1;
	pid_t pid;

	pid = fork();

	if (pid < 0)
		return (1);
	else if (pid == 0)
	{
		ret = execve(dir, args, environ);
		free_env();
		freemem(args, front);
	}
	else
	{
		wait(NULL);
	}
	if (ret == -1)
		return (ret);
	return (0);
}
