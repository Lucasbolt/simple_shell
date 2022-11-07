#include "main.h"

/**
 * main - main exec file
 * Return: 0
 */
int main(void)
{	
	char **tuple;

	tuple = split_fname("chelsea");
	printf("File = %s\ndir = %s\n", tuple[1], tuple[0]);
	return (0);
}
