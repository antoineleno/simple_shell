#include "shell.h"
/**
 * exit_shell - Function to exit shell
 * @input: Input entered by the user
 * @argv: Argument while executing
 * @count: Count of the loop
 * Return: 1 if fail
 */
int exit_shell(char *input, char *argv, int count)
{
	char *copy_of_a1, **args, *copy_of_input;

	if (input == NULL)
	{
		return (0);
	}
	initialize_exit_shell_variables(input, &args, &copy_of_a1);
	if (args[0] == NULL)
	{
		free_mem4(args, copy_of_a1);
		return (0);
	}

	if (_strcmp(args[0], "exit") == 0 && args[1] == NULL)
	{
		free_me3(args, input, copy_of_a1);
		exit(EXIT_SUCCESS);
	}
	if (_strcmp(args[0], "exit") == 0 && args[1] != NULL)
	{
		copy_of_input = malloc(_strlen(args[1]) + 1);
		handle_malloc_faillure(copy_of_input);
		_strcpy(copy_of_input, args[1]);
		if (_strcmp(args[0], "exit") == 0
		&& ((copy_of_input[0] >= 'a' && copy_of_input[0] <= 'z')
		|| (copy_of_input[0] >= 'A' && copy_of_input[0] <= 'Z')))
		{
			fre_mem2(argv, count, args, copy_of_a1, copy_of_input);
			return (1);
		}
		else if (_strcmp(args[0], "exit") == 0 && args[1] != NULL)
		{
			fre_mem1(argv, count, args, copy_of_a1, copy_of_input, input);
		}
	}
	free_allocation(args);
	free(copy_of_a1);
	return (0);
}

/**
 * sigint_handler - Function signals
 * @sig: Sig to handle
*/

void sigint_handler(int sig)
{
	(void) sig;
	signal(SIGINT, sigint_handler);
	_putchar('\n');
	_putchar('$');
	_putchar(' ');
}
