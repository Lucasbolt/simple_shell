#include "main.h"

/**
 * main - main exec file
 * Return: 0
 */
int main(void)
{	
	char **tuple;

	tuple = search("/bin/ls");
	printf("File = %s\ndir = %s\n", tuple[1], tuple[0]);
	dirtest("/bin/", "clear");
	return (0);
}
