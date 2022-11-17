#include "main.h"

/**
 * newcom - adjust argv
 * @argv: argv
 * Return: new args
 */
char **newcom(char **argv)
{
	int count = 0, index, str = 0, index1 = 0, num = 0;
	char **com;

	for (index = 1; argv[index]; index++)
	{
		for (; argv[index][index1]; index1++)
			str++;
		index++;
		count++;

	}
	com = malloc(sizeof(char *) * (count + 2));
	com[num] = malloc(sizeof(char) * (str + 2));
	for (index = 1; argv[index]; index++)
	{
		index1 = 0;
		for (; argv[index][index1]; index1++)
			com[num][index1] = argv[index][index1];
		com[num][index1] = '\0';
		num++;
		com[num] = malloc(sizeof(char) * (str + 2));
	}
	com[num] = NULL;

	return (com);
}
/**
 * pfcom - for non-interactive
 * @argv: argument to process
 * @path: path variables
 * Return: 0 on success, anyother value if it fails.
 */
int pfcom(char **argv, char **path)
{
	char **command, **front;
	int ret, mret = 0, chek;

	command = newcom(argv);
	puts(command[1]);
	puts(path[1]);
	
	front = command;
	chek = checkWord(command[0]);

	if (chek == 1)
		ret = search(command[0]);

	if (chek == 0)
		mret = pathCheck(command, path, front);

	switch (ret)
	{
		case (0):
			mret = startProcess(command, front);
			break;
		case (1):
			freemem(command, front);
			break;
	}
	if (mret == -1)
		return (mret);
	return (0);
}

int nonsense(void)
{
	char *line = malloc(sizeof(char) * 500);

	getline(&line, 0, STDIN_FILENO);
	puts(line);
	return (0);
}
