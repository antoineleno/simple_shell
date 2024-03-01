#include "shell.h"
/**
 * _strcpy - Function to copy of string
 * @dest: String destination
 * @src: String to be copy
 * Return: The dest string
*/

char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _print_number - Function to print an integer
 * @number: Integer to be printed
*/
void _print_number(int number)
{
	char buffer[20];
	char tmp;
	int remainder, i = 0, j, length = 0;

	while (number > 0)
	{
		remainder = number % 10;
		buffer[i] = remainder + '0';
		number = number / 10;
		i++;
		length++;
	}
	buffer[i] = '\0';
	for (j = 0; j < length / 2; j++)
	{
		tmp = buffer[j];
		buffer[j] = buffer[length - j - 1];
		buffer[length - j - 1] = tmp;
	}

	write(STDOUT_FILENO, buffer, length);
}



/**
* _strcat - concatenate two strings using at most n bytes from src
* @dest: input value
* @src: input value
* Return: dest
*/

char *_strcat(char *dest, const char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}

	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}


/**
* _atoi - converts a string to an integer
* @s: string to be converted
* Return: the int converted from the string
*/
int _atoi(char *s)
{
	int r = 0;
	int sign = 1;
	int i = 0;

	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i++;
	}
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
	{
		i++;
	}

	while (s[i] >= '0' && s[i] <= '9')
	{
		if (r > INT_MAX / 10 || (r == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10))
		{
			return (INT_MAX);
		}
		r = r * 10 + (s[i] - '0');
		i++;
	}
	return (r * sign);
}

/**
 * _strspn - Entry point
 * @s: input
 * @accept: input
 * Return: Always 0 (Success)
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int n = 0;
	int r;

	while (*s)
	{
		for (r = 0; accept[r]; r++)
		{
			if (*s == accept[r])
			{
				n++;
				break;
			}
			else if (accept[r + 1] == '\0')
				return (n);
		}
		s++;
	}
	return (n);
}
