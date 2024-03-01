#include "shell.h"
/**
 * free_mem4 - Function to free mem and return
 * @args: Tokenize string
 * @copy_of_a1: Copy of input
*/
void free_mem4(char **args, char *copy_of_a1)
{
	free(copy_of_a1);
	free_allocation(args);
}

/**
 * free_me3 - Function to free mem and exit
 * @args: Input tokenize
 * @input: Input
 * @copy_of_a1: Copy of input
*/
void free_me3(char **args, char *input, char *copy_of_a1)
{
	int exit_code = 0;

	free(copy_of_a1);
	free(input);
	free_allocation(args);
	exit(exit_code);
}
/**
 * fre_mem2 - Function to free mem
 * @argv: Argument vector
 * @count: Count of the loop
 * @args: Tokenize arguments
 * @copy_of_a1: copy çf input
 * @cop: Copy of input
*/
void fre_mem2(char *argv, int count, char **args, char *copy_of_a1, char *cop)
{
	print_message_for_exit(argv, count, args[1]);
	free(copy_of_a1);
	free(cop);
	free_allocation(args);
}

/**
 * fre_mem1 - Function to free mem and exit in exit_shell function
 * @args: Array
 * @copy_of_a1: Copy of input
 * @copy_of_input: copy of input
 * @input: Input
*/
void fre_mem1(char *argv, int count, char **args, char *copy_of_a1, char *copy_of_input, char *input)
{
	int exit_code;
	char error_message_for_exit[1024], number[20];
	exit_code = _atoi(args[1]);
	if (_strchr(args[1], '-') != NULL)
	{
		int_to_string(count, number);
		_strcpy(error_message_for_exit, argv);
		_strcat(error_message_for_exit, ": ");
		_strcat(error_message_for_exit, number);
		_strcat(error_message_for_exit, ": ");
		_strcat(error_message_for_exit, "exit: Illegal number: ");
		_strcat(error_message_for_exit, args[1]);
		_strcat(error_message_for_exit, "\n");
		write(STDERR_FILENO,error_message_for_exit, _strlen(error_message_for_exit));
		exit(2);
	}
	free(copy_of_a1);
	free(copy_of_input);
	free_allocation(args);
	free(input);
	exit(exit_code);
}

/**
 * initialize_exit_shell_variables - function to initialize variable
 * @input: Input
 * @args: Tokenized strings
 * @copy: Copy of input
*/

void initialize_exit_shell_variables(char *input, char ***args, char **copy)
{
	*copy = malloc(_strlen(input) + 1);
	handle_malloc_faillure(*copy);
	_strcpy(*copy, input);
	*args = tokenize_string(*copy);
}
