#include "main.h"

/**
 * search - checks if a file exists
 * Return: tuple[0] = dir
 *			tuple[1] = file
 */
char **search(char *path)
{
	int count = 0, index = 0, diff, hold;
	char *file, *vpath, **tuple[2];

	if (path == NULL)
		exit(-1);

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
	tuple[0] = &vpath;
	tuple[1] = &file;
	return (*tuple);
}
