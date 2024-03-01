#include "shell.h"
/**
 * print_env - Function environment variable
*/

void print_env(void)
{
	char **copy_of_environ;
	unsigned int length;

	copy_of_environ = environ;
	while (*copy_of_environ != NULL)
	{
		length = _strlen(*copy_of_environ);
		write(STDOUT_FILENO, *copy_of_environ, length);
		write(STDOUT_FILENO, "\n", 1);
		copy_of_environ++;
	}
}
