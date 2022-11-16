#include "main.h"

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
char *mygetc()
{
	char *command = malloc(sizeof(char) * 2048);
	int index = 0;
	char n;

	while (1)
	{
		n = getc(stdin);
		if (n == EOF)
		{
			free(command);
			free_env();
			return (NULL);
		}

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
int prompt(char **path)
{
	char **command, *tmp, *input, **front;
	int ret = 2, chek, count, out;
	char *message = "($) ";

	while (1)
	{
		write(STDOUT_FILENO, message, strlen(message));
		input = mygetc();

		if ((strlen(input) == 0))
		{
			free(input);
			continue;
		}
		if (!input)
		{
			free(input);
			return (END);
		}
		out = mexit(input);
		if (out == EXIT)
			return (out);
		tmp = modifier(input);
		free(input);
		count = delim_count(tmp);
		command = splitit(tmp, count);
		front = command;
		chek = checkWord(command[0]);

		if (chek == 1)
			ret = search(command[0]);

		if (chek == 0)
			pathCheck(command, path, front);

		switch (ret)
		{
			case (0):
				startProcess(command, front);
				break;
			case (1):
				freemem(command, front);
				break;
		}
	}
}
