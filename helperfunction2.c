#include "shell.h"

/**
 * _putchar - Function to print a single character
 * @c: character to be printed
 * Return: Always one on success
*/

int _putchar(char c)
{
	return (write(STDIN_FILENO, &c, 1));
}


/**
 * _strchr - Find the first occurence of a character in a string
 * @s: The string to search
 * @c: The character to find
 * Return: Pointer to the first occurence of the character, or NULL
*/

char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] != '\0'; i++)
	{
		if (s[i] == c)
		{
			return (&s[i]);
		}
	}
	return (NULL);
}

/**
 * message - Function to print the error message
 * @count: Count of the looop
*/


void message(int count)
{
	_putchar(':');
	_putchar(' ');
	if (count < 10)
	{
		_putchar(count + '0');
	}
	else
	{
		_print_number(count);
	}
	_putchar(':');
	_putchar(' ');
}

/**
 * notfound_message - Function to print the message not found
*/

void notfound_message(void)
{
	char message[9] = "not found";
	int i = 0;

	_putchar(':');
	_putchar(' ');
	while (message[i] != '\0')
	{
		_putchar(message[i]);
		i++;
	}
	_putchar('\n');
}
/**
 * _print_argv - Function to print a string
 * @string: String to be printed
*/

void _print_argv(char *string)
{
	int i = 0;

	while (string[i] != '\0')
	{
		_putchar(string[i]);
		i++;
	}
}
