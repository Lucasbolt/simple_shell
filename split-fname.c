#include "main.h"

/**
 * check - checks if @file1 == @file2
 * @file1: file 1
 * @file2: file2
 * Return: 1 on failure; 0 on success
 */
int check(char *file1, char *file2)
{
	int index1 = 0, index2 = 0;

	if (strlen(file1) != (strlen(file2)))
		return (1);

	while (file1[index1] && file2[index2])
	{
		if (file1[index1] != file2[index2])
			return (1);
		index1++;
		index2++;
	}

	return (0);

}

/**
 * dirtest - checks if @file exist in a @dir
 * @dir: directory to check for file
 * @file: file to look for
 * @errno: 1 to show error, 0 for otherwise
 * Return: 0 on success; 1 on failure.
 */
int dirtest(char *dir, char *file, int errno)
{
	struct dirent *pDirent;
	DIR *pDir;
	int res;

	pDir = opendir(dir);
	if (pDir == NULL)
	{
		if (errno == 1)
			printf("Cannot open directory %s\n", dir);
		return (1);
	}

	while ((pDirent = readdir(pDir)) != NULL)
	{
		res = check(pDirent->d_name, file);
		if (res == 0)
		{
			closedir(pDir);
			return (0);
		}
	}
	if (errno == 1)
		printf("./shell: No such file or directory\n");
	closedir(pDir);
	return (1);
}


/**
 * search - checks if a file exists
 * @path: path to file
 * Return: @ret i.e return value of func dirtest
 */
int search(char *path)
{
	int count = 0, index = 0, diff, hold, ret;
	char *file, *vpath;

	if (path == NULL)
		exit(-1);
	if (path[0] == '\n' || path[0] == '\0')
		return (-1);
	while (path[count] != '\0')
		count += 1;

	hold = count--;

	for (; path[count] != '/'; count--)
		index++;
	file = malloc(sizeof(char) * (index + 1));

	diff = hold - index;

	vpath = malloc(sizeof(char) * diff);

	for (count = 0; count < diff; count++)
	{
		vpath[count] = path[count];
	}
	for (count = 0; path[diff]; diff++)
	{
		file[count] = path[diff];
		count++;
	}
	file[count] = '\0';
	ret = dirtest(vpath, file, 1);
	free(file);
	free(vpath);
	return (ret);
}
