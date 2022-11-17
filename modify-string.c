#include "main.h"
/**
 * modifier - deletes multiple ' ' in string
 * @string: string input
 * Return: pointer to string
 */
char *modifier(char *string)
{
	int size = 0;
	char *s = string;
	char *a;
	int index = 0, i = 0;

	if (string == NULL || string[0] == '\0')
		return (NULL);
	for (index = 0; s[index]; index++)
	{
		if (s[index] !=  ' ')
			break;
		index++;
	}
	size = strlen(s);
	size += 2;
	a = malloc(size * sizeof(char));
	for (i = 0; i < size; i++)
		a[i] = '\0';
	for (i = 0; s[index]; i++)
	{
		while ((s[index] == ' ') && (s[index + 1] == ' '))
			index++;
		if (s[index] == ' ' && s[index + 1] == '\0')
		{
			a[i] = '\0';
			break;
		}
		a[i] = s[index];
		index++;
	}
	return (a);
}
