#include "shell.h"
/**
 * _search_path_and_ex - Function to search the path and exectue the command
 * @input: Input of the user
 * @i: Count
 * @argv: First argumeent enter by the user.
 * Return: The flag
*/
int _search_path_and_ex(char *input, int i, char *argv)
{
	char *path;
	char copy_of_input[1024], number[20];
	int flag = 0;
	char **args, **second_args, error_message[1024];

	if (input == NULL || _strspn(input, " \t\n\r") == _strlen(input))
	{
		return (flag);
	}

	_strcpy(copy_of_input, input);
	second_args = tokenize_string(copy_of_input);
	if (_strchr(second_args[0], '/') == NULL)
	{
		args = tokenize_string(input);
		path = _search_path(args[0]);
		if (path == NULL)
		{
			int_to_string(i, number);
			_strcpy(error_message, argv);
			_strcat(error_message, ": ");
			_strcat(error_message, number);
			_strcat(error_message, ": ");
			_strcat(error_message, second_args[0]);
			_strcat(error_message, ": not found\n");
			write(STDERR_FILENO, error_message, _strlen(error_message));
			i++;
			exit(127);
			free_allocation(args);
			free_allocation(second_args);
			return (flag);
		}
		else
		{
			args[0] = _strdup(path);
			free(path);
			execute_commands(args, i, argv);
			flag = 1;
			free_allocation(args);
			free_allocation(second_args);
			return (flag);
		}
	}
	else
	{
		free_allocation(second_args);
		return (flag);
	}
}

/**
 * _search_path - Function to searh a path
 * @input: Input to search its path
 * Return: The path if found otherwise NULL
*/

char *_search_path(char *input)
{
	char *path, *copy_of_path, *directory, *result;
	char full_path[1024];
	char copy_of_directory[1024];
	char copy_of_input[1024];

	if (input == NULL)
	{
		return (NULL);
	}
	path = _getenv("PATH");
	if (path == NULL)
	{
		perror("error");
		return (NULL);
	}
	copy_of_path = _strdup(path);
	if (copy_of_path == NULL)
	{
		perror("error");
		return (NULL);
	}
	directory = strtok(copy_of_path, ":");
	while (directory != NULL)
	{
		_strcpy(copy_of_directory, directory);
		_strcpy(copy_of_input, input);
		_strcat(copy_of_directory, "/");
		_strcat(copy_of_directory, copy_of_input);
		_strcpy(full_path, copy_of_directory);
		if (access(full_path, X_OK) == 0)
		{
			result = _strdup(full_path);
			free(copy_of_path);
			free(input);
			return (result);
		}
		directory = strtok(NULL, ":");
	}
	free(copy_of_path);
	return (NULL);
}

/**
 * my_execute - Function to exexute command
 * @count: Counter for the loop
 * @argv: Argument enter while compiling
 * @string: string
*/

void my_execute(char *string, int count, char *argv)
{
	char **args;
	char *path;
	char copy_of_command[100];
	int i = 0, flag = 0;

	args = tokenize_string(string);
	path = _search_path(args[0]);

	if (path == NULL)
	{
		_print_argv(argv);
		_strcpy(copy_of_command, args[0]);
		message(count);
		while (copy_of_command[i] != '\0')
		{
			_putchar(copy_of_command[i]);
			i++;
		}
		notfound_message();
		free_allocation(args);
		return;
	}
	args[0] = _strdup(path);
	if (flag == 0)
	{
		execute_commands(args, count, argv);
	}
	free_allocation(args);
	free(path);
}

/**
 * check_for_semi_column - Function to check wether ; exit or not
 * @string: String to search in
 * @argv: First argument enter by the user
 * @count: Count of the loop
 * Return: 1 if found otherwise 0
*/

int check_for_semi_column(char *string, char *argv, int count)
{
	int i = 0, flag = 0;
	char *copy_of_string;

	copy_of_string = malloc(_strlen(string) + 1);
	handle_malloc_faillure(copy_of_string);
	_strcpy(copy_of_string, string);

	while (copy_of_string[i] != '\0')
	{
		if (copy_of_string[0] == ';' && !i)
		{
			_print_argv(argv);
			message(count);
			write(STDOUT_FILENO, " Syntax error: ", 15);
			_putchar('"');
			_putchar(';');
			_putchar('"');
			write(STDOUT_FILENO, " unexpected\n", 12);
			string[i] = '\0';
			flag = 2;
			free(copy_of_string);
			return (flag);
		}
		if (copy_of_string[i] == ';')
		{
			flag = 1;
			free(copy_of_string);
			return (flag);
		}
		i++;
	}
	free(copy_of_string);
	return (flag);
}

/**
 * fms - Function to free multiple allocation and exit
 * @one: First string
 * @two: SEcond_string
 * @three: Third string
 * @a: First array
 * @b: Second array
 * @c: string
 * @d: count
 * Return: 1 on succes otherwise 0
*/
int fms(char *one, char *two, char *three, char **a, char **b, char *c, int d)
{
	int exit_code = 0;
	char *copy_of_a1;

	if (_strcmp(a[0], "exit") == 0 && a[1] != NULL)
	{
		copy_of_a1 = malloc(_strlen(a[1]) + 1);
		handle_malloc_faillure(copy_of_a1);
		_strcpy(copy_of_a1, a[1]);
	}
	if (_strcmp(a[0], "exit") == 0 && a[1] == NULL)
	{
		free(one);
		free(two);
		free(three);
		free_allocation(a);
		free_allocation(b);
		exit(exit_code);
	}
	else if (_strcmp(a[0], "exit") == 0
	&& a[1] != NULL && ((copy_of_a1[0] >= 'a' && copy_of_a1[0] <= 'z')
	|| (copy_of_a1[0] >= 'A' && copy_of_a1[0] <= 'Z')))
	{
		free(copy_of_a1);
		print_message_for_exit(c, d, a[1]);
		return (1);
	}
	else if (_strcmp(a[0], "exit") == 0 && a[1] != NULL)
	{
		exit_code = _atoi(a[1]);
		free(one);
		free(two);
		free(three);
		free_allocation(a);
		free_allocation(b);
		free(copy_of_a1);
		exit(exit_code);
	}
	return (0);
}
