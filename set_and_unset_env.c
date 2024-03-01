#include "shell.h"
/**
 * _setenv - Function to set environment variable
 * @name: Variable to be added
 * @value: Value of the variable
 * @overwrite: Description of the action
 * Return: Always 0 (Success) otherwise -1
*/
int _setenv(const char *name, const char *value, int overwrite)
{
	char **nwe, new_variable[1050], **second_environ, copy_of_nwe[1050];
	int env_count;

	nwe = environ;
	second_environ = environ;
	if (name == NULL || name[0] == '\0')
	{
		return (0);
	}

	while (*nwe != NULL)
	{
		if (_strncmp(*nwe, name, _strlen(name)) == 0 && (*nwe)[_strlen(name)] == '=')
		{
			if (!overwrite)
			{
				return (0);
			}
			else
			{
				_strcpy(copy_of_nwe, *nwe);
				concatTwostrings(name, value, copy_of_nwe);
				return (1);
			}
		}
		nwe++;
	}
	concatTwostrings(name, value, new_variable);
	while (*second_environ != NULL)
	{
		env_count++;
		second_environ++;
	}
	*second_environ = new_variable;
	*(second_environ + 1) = NULL;
	return (1);
}

/**
 * _unsetenv - Unset a variable defined
 * @name: name of the variable to unsert
 * Return: 0 on success otherwise -1
*/

int _unsetenv(const char *name)
{
	char **nwe, **temp;

	nwe = environ;

	if (name == NULL || *name == '\0')
	{
		return (0);
	}
	while (*nwe != NULL)
	{
		if (_strncmp(*nwe, name, _strlen(name)) == 0 && (*nwe)[_strlen(name)] == '=')
		{
			temp = nwe;
			while (*(temp + 1) != NULL)
			{
				*temp = *(temp + 1);
				temp++;
			}
			*temp = NULL;
			return (0);
		}
		nwe++;
	}

	return (0);
}

/**
 * concatTwostrings - Function to concatenate two strings
 * @str1: First string
 * @str2: Second tring
 * @result: Final string
*/
void concatTwostrings(const char *str1, const char *str2, char *result)
{
	_strcpy(result, str1);
	_strcat(result, "=");
	_strcat(result, str2);
}


/**
 * _getenv - Function to get environment variable
 * @name: Variable to find
 * Return: Full path if found otherwise NULL
*/
char *_getenv(const char *name)
{
	char **nwe;
	int n;

	nwe = environ;
	while (*nwe != NULL)
	{
		if (strncmp(*nwe, name, strlen(name)) == 0 && (*nwe)[strlen(name)] == '=')
		{
			n = strlen(name) + 1;
			return (*nwe + n);
		}
		nwe++;
	}
	return (NULL);
}
