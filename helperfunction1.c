#include "shell.h"

/**
 * _strlen - Function to find the length of the string
 * @string: String to find the length
 * Return: The length of the string
*/

unsigned int _strlen(const char *string)
{
	int length = 0;

	if (string == NULL)
	{
		return (0);
	}

	else
	{
		while (*string != '\0')
		{
			length++;
			string++;
		}
	}
	return (length);
}


/**
 * _strncmp - Function to compare n characters in a string.
 * @s1: First string to be compared
 * @s2: Second string to be compared
 * @n: Number of character to be compared
 * Return: 0 is equal otherse not equal
*/

int _strncmp(const char *s1, const char *s2, size_t n)
{
	int m;
	size_t i = 0;

	while (s1[i] != '\0' && s2[i] != '\0'  && i < n)
	{
		m = s1[i] - s2[i];
		if (m != 0)
		{
			return (m);
		}
		i++;
	}

	if (i == n)
	{
		return (0);
	}

	return (s1[i] - s2[i]);
}

/**
 * _strcmp - Function to compare n characters in a string.
 * @s1: First string to be compared
 * @s2: Second string to be compared
 * Return: 0 is equal otherse not equal
*/

int _strcmp(const char *s1, const char *s2)
{
	int m;
	size_t i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		m = s1[i] - s2[i];
		if (m != 0)
		{
			return (m);
		}
		i++;
	}

	return (s1[i] - s2[i]);
}

/**
 * _strdup - Function to duplicate a string.
 * @original_string: String to be duplicated.
 * Return: The duplicate function.
*/

char *_strdup(const char *original_string)
{
	int length_of_original_string = 0;
	const char *new_original_string = original_string;
	int i = 0;
	char *buffer;

	while (*new_original_string != '\0')
	{
		length_of_original_string++;
		new_original_string++;
	}

	buffer = malloc(length_of_original_string + 1);
	if (buffer == NULL)
	{
		return (NULL);
	}

	if (buffer != NULL)
	{
		while (*original_string != '\0')
		{
			buffer[i] = *original_string;
			i++;
			original_string++;
		}
	}

	buffer[i] = '\0';

	return (buffer);
}



/**
* _strncat - concatenate two strings using at most n bytes from src
* @dest: input value
* @src: input value
* @n: input value
* Return: dest
*/

char *_strncat(char *dest, char *src, int n)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}

	j = 0;
	while (j < n && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

