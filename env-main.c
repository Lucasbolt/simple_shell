#include "main.h"

/**
 * main - main exec file
 * @argc: arg count
 * @argv: argument array
 * Return: 0
 */
int main(int argc, __attribute__ ((unused)) char *argv[])
{
	char **front;
	char **path = epath();
	int ret = 0;

	environ = makenv();
	front = path;

	if (argc != 1)
	{
		freemem(path, front);
		free_env();
		return (ret);
	}
	else
	{
		while (1)
		{
			ret = prompt(path);
			if (ret == END || ret == EXIT)
			{
				free_env();
				freemem(path, front);
				/*write(STDOUT_FILENO, "\n", 1);*/
				exit(ret);
			}
		}
	}
	free_env();
	return (0);
}
