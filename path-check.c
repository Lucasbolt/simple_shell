#include "main.h"

/**
 * numberPath - calculates amount of path dir
 * @path: path delimited with ':'.
 * Return: number of dirs in path.
 */
int numberPath(char *path)
{	
	int index = 0, num = 0;

	if (path == NULL)
	{
		puts("error");
		exit(100);
	}


	while (path[index] != '\0')
	{
		if (path[index] == ':')
			num++;
		index++;
	}
	num++;
	return (num);
}
/**
 * epath - generates path dir
 * Return: array of path dir.
 */
char **epath(void)
{

	int index = 5, index1 = 0, num = 0;
	char **PATH;
	char **path = fetch_env("PATH");
	int count = numberPath(*path + 5);
	char *dpath = path[0];

	PATH = malloc(sizeof(char *) * (count + 1));
	PATH[num] = malloc(sizeof(char) * 100);
	while (dpath[index] != '\0')
	{
		if (dpath[index] == ':')
		{
			PATH[num][index1] = '\0';
			num++;
			index1 = 0;
			index++;
			PATH[num] = malloc(sizeof(char) * 100);
		}
		PATH[num][index1] = dpath[index];
		index++;
		index1++;
	}
	PATH[num][index1] = '\0';
	PATH[num + 1] = NULL;
	return (PATH);
}
/**
 * pathCheck - checks for command in PATH
 * @command: command to check for
 * Description: if command is found, it is executed
 *				and 0 is returned.
 * Return: 0 on success, 1 on failure
 */
int pathCheck(char **command, char **path, char **front)
{
	char *dir, *ptr, *error = "./shell: No such file or directory\n";
	int index = 0, ret;

	while (path[index] != NULL)
	{
		ret = dirtest(path[index], command[0], 0);

		if (ret == 0)
		{
			dir = malloc(sizeof(char) * 500);
			ptr = strcpy(dir, path[index]);
			ptr = strcat(dir, "/");
			ptr = strcat(dir, command[0]);
			ret = pathProcess(ptr, command, front);
			free(dir);
			return (ret);
		}

		else
		{
			index++;
			continue;
		}
	}
	freemem(command, front);
	write(STDERR_FILENO, error, strlen(error));
	return (1);
}
