#include "main.h"

/**
 * check - checks if @file1 == @file2
 * @file1: file 1
 * @file2: file2
 * Return: 1 on failure; 0 on success
 */
int check(char *file1, char *file2)
{
	int index1, index2 = 0;

	for (index1 = 0; (file1[index1]); index1++)
	{
		if (file1[index1] != file2[index2])
			return (1);
		index2++;
	}
	if (index1 != index2)
		return (1);

	return (0);

}

/**
 * dirtest - checks if @file exist in a @dir
 * @dir: directory to check for file
 * @file: file to look for
 * Return: 0 on success; 1 on failure.
 */
int dirtest(char *dir, char *file)
{
	struct dirent *pDirent;
	DIR *pDir;
	int res;

	pDir = opendir(dir);
	if (pDir == NULL)
	{
		printf("Cannot open directory %s\n", dir);
		return (1);
	}

	while ((pDirent = readdir(pDir)) != NULL)
	{
		puts(pDirent->d_name);
		res = check(pDirent->d_name, file);
		if (res == 0)
		{
			printf("size of pd = %lu; size of file %lu\n", strlen(pDirent->d_name), strlen(file));
			printf("The file matched - %s && %s\n ",pDirent->d_name, file);
			break;
		}
	}

	closedir(pDir);
	return (0);
}
