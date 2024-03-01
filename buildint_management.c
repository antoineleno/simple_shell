#include "shell.h"
/**
 * build_int_function_management - Function to manage build_in function
 * @input: Input enter by the user
 * @count: count of the loop
 * @argv: ARgument
 * Return: 1 on success otherwise 0
*/
int build_int_function_management(char *input, int count, char *argv)
{
	char copy_of_input[100], **args;

	if (input == NULL || _strspn(input, " \t\n\r") == _strlen(input))
	{
		return (0);
	}
	_strcpy(copy_of_input, input);
	args = tokenize_string(copy_of_input);
	if (_strcmp(args[0], "env") == 0)
	{
		print_env();
		free_allocation(args);
		return (1);
	}
	else if (_strcmp(args[0], "setenv") == 0 || _strcmp(args[0], "unsetenv") == 0)
	{
		manange_set_and_unset(args);
		free_allocation(args);
		return (1);
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		change_current_working_dir(args, argv, count);
		free_allocation(args);
		return (1);

	}
	free_allocation(args);
	return (0);
}

/**
 * change_current_working_dir - Function to change current
 * working directory
 * @args: All argument tokenized
 * @argv: argv 1 while compiling
 * @count: Count for the loop
*/
void change_current_working_dir(char **args, char *argv, int count)
{
	static char previous_directory[1024];
	char current_working_dir[1024], *home_dir;
	char new_directory[1024], back_directory[1024];

	if (getcwd(current_working_dir, sizeof(current_working_dir)) == NULL)
	{
		perror("getcwd");
	}
	_strcat(current_working_dir, "/");
	if (args[1] == NULL)
	{
		strcpy(previous_directory, current_working_dir);
		home_dir = _getenv("HOME");
		chdir(home_dir);
		_setenv("PWD", "$HOME", 1);
	}
	else if (_strcmp(args[1], "..") == 0)
	{
		getcwd(back_directory, 1024);
		manage_back_directory(back_directory);
	}
	else if (args[1] != NULL && _strcmp(args[1], "-") != 0)
	{
		strcpy(previous_directory, current_working_dir);
		strcat(current_working_dir, args[1]);
		if (chdir(current_working_dir) == -1)
		{
			message_error_for_cd(args[1], argv, count);
		}
		_setenv("PWD", current_working_dir, 1);
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		getcwd(new_directory, 1024);
		chdir(previous_directory);
		_setenv("PWD", previous_directory, 1);
		strcpy(previous_directory, new_directory);
	}
}

/**
 * manage_back_directory - Function to manage cd ..
 * @path: Path
*/
void manage_back_directory(char *path)
{
	char *last_slash;
	char *pointer;

	pointer = path;
	last_slash = NULL;

	while (*pointer != '\0')
	{
		if (*pointer == '/')
		{
			last_slash = pointer;
		}
		pointer++;
	}

	if (last_slash != NULL)
	{
		*last_slash = '\0';
		chdir(path);
		_setenv("PWD", path, 1);
	}
}

/**
 * manange_set_and_unset - Function to manage the set and unset variable
 * @args: Array that content all the sub strings enter
*/

void manange_set_and_unset(char **args)
{
	int overwrite;

	if (_strcmp(args[0], "setenv") == 0)
	{

		if (args[1] == NULL)
		{
			return;
		}
		else if (args[2] == NULL && args[1] != NULL)
		{
			_setenv(args[1], "", 0);
		}
		else if (args[3] != NULL)
		{
			overwrite = _atoi(args[3]);
			_setenv(args[1], args[3], overwrite);
		}
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		if (args[1] == NULL)
		{
			return;
		}
		_unsetenv(args[1]);

	}
}

/**
 * message_error_for_cd - Print error message when cd fail
 * @args: directory provied
 * @argv: Command line vector while compiling
 * @count: Count for the looop
*/
void message_error_for_cd(char *args, char *argv, int count)
{
	write(STDOUT_FILENO, argv, _strlen(argv));
	_putchar(':');
	_putchar(' ');
	_print_number(count);
	_putchar(':');
	_putchar(' ');
	_putchar('c');
	_putchar('d');
	_putchar(':');
	_putchar(' ');
	_putchar('c');
	_putchar('a');
	_putchar('n');
	_putchar('\'');
	_putchar('t');
	_putchar(' ');
	_putchar('c');
	_putchar('d');
	_putchar(' ');
	_putchar('t');
	_putchar('o');
	_putchar(' ');
	write(STDOUT_FILENO, args, _strlen(args));
	_putchar('\n');
}
