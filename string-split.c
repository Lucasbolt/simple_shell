#include "main.h"

/**
 * delim_count - counts number of words in a string
 * @command: strings to check
 * Return: number of words
 */
int delim_count(char *command)
{
	int words = 0, index;

	if (command == NULL || command[0] == '\0')
		return (-1);

	for (index = 0; command[index]; index++)
	{
		if (command[index] == ' ' && (command[index + 1] != ' '
			&& command[index + 1] != '\0'))
			words++;
		/*index++;*/
	}
	words++;

	return (words);
}
/**
 * string_splitter - splits strings into substings
 * @command: the string to split
 * Return: return a pointer array of substrings
 */
char **string_splitter(char *command)
{
	int wcount, index = 0, index1 = 0, num = 0;
	char **tokens, *string;

	if (command == NULL)
		return (NULL);
	string = modifier(command);
	wcount = delim_count(string);

	tokens = malloc(sizeof(char *) * (wcount));
	if (tokens == NULL)
		return (NULL);
	tokens[num] = malloc(sizeof(char) * strlen(string));

	while (string[index])
	{
		if (string[index] == ' ')
		{
			tokens[num][index1] = '\0';
			num++;
			tokens[num] = malloc(sizeof(char) * strlen(string));
			index++;
			index1 = 0;
		}
		tokens[num][index1] = string[index];
		index++;
		index1++;

		if (string[index] == '\0')
		{
			/*tokens[num + 1] = NULL;*/
			break;
		}

	}
	free(string);
	return (tokens);
}
