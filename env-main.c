#include "main.h"



/**
 * main - main exec file
 * @argc: arg count
 * @argv: argument array
 * Return: 0
 */
int main(int argc, char **argv)
{
	char **path = epath();
	int ret;

	if (argc > 1)
		puts(argv[1]);
	else
	{
		environ = makenv();
		ret = prompt(path);
		if (ret == END || ret == EXIT)
		{
			free_env();
			free(path);
			write(STDOUT_FILENO, "\n", 1); 
			exit(ret);
		}
	}
	free_env();
	free(path);
	return (0);
}
