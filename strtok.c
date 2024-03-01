#include "shell.h"
/**
 * _strtok - Function to tokenize a string
 * @str: String to searc a delimiter in
 * @delim: Delimiters
 * Return: The pointer to the first occurnce if found otherwise Null
*/

char *_strtok(char *str, char *delim)
{
	static char *next_token;
	char *start_token;

	if (str != NULL)
	{
		next_token = str;
	}
	else if (next_token == NULL)
	{
		return (NULL);
	}

	while (*next_token != '\0' && _strchr(delim, *next_token) != NULL)
	{
		next_token++;
	}

	if (*next_token == '\0')
	{
		next_token = NULL;
		return (NULL);
	}

	start_token = next_token;

	while (*next_token != '\0' && _strchr(delim, *next_token) == NULL)
	{
		next_token++;
	}
	if (*next_token != '\0')
	{
		*next_token = '\0';
		next_token++;
	}
	return (start_token);
}

