#include "main.h"

/**
 * prompt - imitates the shell prompt.
 * Description: it waits for commands to be entered
 * Return: returns 0 on exit
 */
int prompt(void)
{
	char command[1024];

	while (1)
	{
		printf("($) ");
		
		if (fgets(command, 1023, stdin) == NULL)
			exit(-1);
		continue;
	}
}
