#include "main.h"

/**
 * makenv - Creates a copy of the environment.
 *
 * Return: If an error occurs - NULL.
 *         O/w - a double pointer to the new copy.
 */
char **makenv(void)
{
	char **new_environ;
	size_t size;
	int index;

	for (size = 0; environ[size]; size++)
		;

	new_environ = malloc(sizeof(char *) * (size + 1));
	if (!new_environ)
		return (NULL);

	for (index = 0; environ[index]; index++)
	{
		new_environ[index] = malloc(strlen(environ[index]) + 1);

		if (!new_environ[index])
		{
			for (index--; index >= 0; index--)
				free(new_environ[index]);
			free(new_environ);
			return (NULL);
		}
		strcpy(new_environ[index], environ[index]);
	}
	new_environ[index] = NULL;

	return (new_environ);
}


/**
 * fetch_env - Gets an environmental variable from the PATH.
 * @var: The name of the environmental variable to get.
 *
 * Return: If the environmental variable does not exist - NULL.
 *         Otherwise - a pointer to the environmental variable.
 */
char **fetch_env(const char *var)
{
	int index, len;

	len = strlen(var);
	for (index = 0; environ[index]; index++)
	{
		if (strncmp(var, environ[index], len) == 0)
			return (&environ[index]);
	}

	return (NULL);
}

/**
 * _exit - checks if input is an exit command
 * @input: command entered
 * Return: 0 if true, otherwise
 */
int mexit(char *input)
{
	int ret;

	ret = strcmp(input, "exit");
	if (ret == 0)
		return (-3);
	return (ret);
}
