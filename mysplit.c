#include "main.h"

/**
 * splitit - splits strings into substrings
 * @string: string to split
 * @words: number of substrings
 * Returns: pointer array to substrings
 */
char **splitit(char *string, int words)
{
	int num = 0, index, index1 = 0, wc = 400;
	char **tokens;
	
	if (string == NULL || words <= 0)
		return (NULL);

	tokens = malloc(sizeof(char *) * (words + 2));
	if (!tokens)
		return (NULL);
	tokens[num] = malloc(wc * sizeof(char));
	for (index = 0; string[index];)
	{
		if (string[index] == ' ')
		{
			tokens[num][index1] = '\0';
			num++;
			index++;
			index1 = 0;
			tokens[num] = malloc(wc * sizeof(char));

		}
		tokens[num][index1] = string[index];
		index++;
		index1++;
	}
	tokens[num][index1] = '\0';
	num++;
	tokens[num] = NULL;
	tokens[num + 1] = NULL;
	free(string);
	return (tokens);
}
