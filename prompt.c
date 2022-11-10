#include "main.h"

/**
 * startProcess - forks a process
 * @command: command to execute
 * @args: arguments
 * Return: 0 on success
 */
int startProcess(char *command, char **args)
{
	pid_t pid;

	pid = fork();

	if (pid < 0)
		return (1);
	else if (pid == 0)
		execvp(command, args);
	else
	{
		wait(NULL);
	}
	return (0);
}

/**
 * checkWord - check if command is a directorty or word
 * @command: command to check
 * Return: 1 if directory, 0 if word
 */
int checkWord(char *command)
{
	int index = 0;

	if (command == NULL || command[0] == '\0')
		return (-1);

	while (command[index] != '\0')
	{
		if (command[index] == '/')
			return (1);
		index++;
	}
	return (0);
}
/**
 * mygetc - reads characters from stdin
 * Return: returns the read @command
 */
char *mygetc(void)
{
	char *command = malloc(sizeof(char) * 1024);
	int index = 0;
	char n;

	while ((n = getc(stdin)) != '\n')
	{
		if (n == EOF)
			exit(-1);

		if (n == '\n')
		{
			command[index] = '\0';
			break;
		}
		command[index] = n;
		index++;
	}
	return (command);
}

/**
 * prompt - imitates the shell prompt.
 * Description: it waits for commands to be entered
 * Return: returns 0 on exit
 */
int prompt(void)
{
	char *arg[2];
	char *command;
	int ret = 2, chek;

	while (1)
	{
		printf("($) ");

		command = mygetc();
		chek = checkWord(command);
		if (chek == 1)
			ret = search(command);

		if (chek == 0)
			pathCheck(command);

		if (ret == 0)
		{
			arg[0] = command;
			arg[1] = NULL;
			startProcess(command, arg);
		}
		free(command);
		continue;
	}
}
