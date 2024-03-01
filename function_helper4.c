#include "shell.h"
/**
 * print_message_for_exit - Function to print error message
 * @argv: Argument enter enter while executing
 * @count: Count for the loop
 * @input: Command enter
*/
void print_message_for_exit(char *argv, int count, char *input)
{
	write(STDOUT_FILENO, argv, _strlen(argv));
	_putchar(':');
	_putchar(' ');
	_print_number(count);
	_putchar(':');
	write(STDOUT_FILENO, " exit: Illegal number: ", 24);
	write(STDOUT_FILENO, input, _strlen(input));
	_putchar('\n');
}

/**
 * functions - Helper function
 * @com: command
 * @count: count of the loop
 * @argv: argument while executing
 * @antoine: array
 * @first: command to execute
*/
void functions(char **com, int count, char *argv, char **antoine, char *first)
{
	com = tokenize_string(first);
	execute_commands(com, count, argv);
	free_allocation(com);
	free_allocation(antoine);
}

/**
 * tail_of_comments - tail of comment file
 * @args: argument tokenize
 * @c_in: first input
 * @s_c_in: second input
 * Return: alway one
*/

int tail_of_comments(char **args, char *c_in, char *s_c_in)
{
	free_allocation(args);
	free_two_string(c_in, s_c_in);
	return (1);
}

/**
 * free_5memory - Function to free mem
 * @antoine: first mem
 * @args: second
 * @s_c_in: Third
 * @c_in: Fourth
*/

void free_5memory(char **antoine, char **args, char *s_c_in, char *c_in)
{
	if (antoine[0] == NULL)
	{
		free_allocation(antoine);
		free_allocation(args);
		free(s_c_in);
		free(c_in);
	}
}


/**
 *  handle_malloc_faillure - Function to handle mem fail
 * @string: String to allocated memory for
 * Return: flag
*/

char  *handle_malloc_faillure(char *string)
{
	if (string == NULL)
	{
		return (NULL);
	}
	return (string);
}
