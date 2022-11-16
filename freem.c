#include "main.h"

/**
 * freemem - frees generated tokens
 * @tokens: pointer to heap mem
 * Return: 0 on success, 1 on error
 */
int freemem(char **tokens, char **front)
{
	int index = 0;
	
	for (; tokens[index] || tokens[index + 1]; index++)
	{
		free(tokens[index]);
	}
	free(front);
	return (0);
}

/**
 * free_env - Frees the the environment copy.
 */
void free_env(void)
{
	int index;

	for (index = 0; environ[index]; index++)
		free(environ[index]);
	free(environ);
}
