#include "main.h"

/**
 * pathCheck - checks for command in PATH
 * @command: command to check for
 * Description: if command is found, it is executed
 *				and 0 is returned.
 * Return: 0 on success, 1 on failure
 */
int pathCheck(char *command)
{
	int index = 0, ret;
	char *args[2];
	char *PATH[22] = {
					"/usr/local/bin/", "/usr/bin/", "/bin/", "/usr/local/games/",
					"/usr/games/", "/usr/share/games/", "/usr/local/sbin/",
					"/usr/sbin/", "/sbin/", "/home/lucasbolt/.local/bin/",
					"/snap/bin/", NULL
				};

	while (PATH[index] != NULL)
	{
		ret = dirtest(PATH[index], command, 0);

		if (ret == 0)
		{
			args[0] = command;
			args[1] = NULL;
			ret = startProcess(command, args);
			return (ret);
		}

		else
		{
			index++;
			continue;
		}
	}
	printf("./shell: No such file or directory\n");
	return (1);
}
