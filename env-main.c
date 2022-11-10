#include "main.h"

/**
 * main - main exec file
 * @argc: arg count
 * @argv: argument array
 * Return: 0
 */
int main(int argc, char **argv)
{
	if (argc > 1)
		puts(argv[1]);
	else
		prompt();
	return (0);
}
