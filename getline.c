#include "shell.h"
/**
 * _getline - Function to read the entire line
 * @lineptr: Pointer to a pointer to a character
 * @n: Pointer to a  variable
 * @stream: Pointer to a file
 * Return: The number of characters read.
*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t byte_read;
	size_t i = 0;
	static char *buffer;
	char *new_buffer;

	if (*n == 0 && *lineptr == NULL)
	{
		*n = 128;
		buffer = (char *)malloc(*n);
		if (buffer == NULL)
		{
			return (-1);
		}
		*lineptr = buffer;
	}
	buffer = *lineptr;
	fflush(stdout);
	while ((byte_read = read(fileno(stream), &buffer[i], 1)) != -1 &&
	buffer[i] != '\n' && buffer[i] != EOF)
	{
		if ((i + 1) > *n)
		{
			new_buffer = (char *)malloc(2 * (*n));

			if (new_buffer == NULL)
			{
				return (-1);
			}
			buffer = new_buffer;
			*lineptr = buffer;
			*n *= 2;
		}
		i++;
	}
	buffer[i] = '\0';
	if (byte_read == -1 && i == 0)
	{
		return (-1);
	}
	return (i);
}
