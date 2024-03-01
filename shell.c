#include "shell.h"
/**
 * main - Entry point
 * Description: Main function to print the shell prompt
 * take command, execute them and handle error.
 * @argc: Number of argument enter while executing
 * @argv: Argument entered
 * Return: Always 0 (Success)
*/
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		process_interrative_mode(argv);
	}
	else
	{
		process_non_interrative_mode(argv);
	}
	return (0);
}




/**
 * tokenize_string - Function to tokenise a string
 * @string: String to be stokenized
 * Return: The array contening all the sub_args tokenised.
*/

char **tokenize_string(char *string)
{
	int args_count = 0;
	char *token;
	char **args;

	if (string == NULL)
	{
		perror("Tokenize_string: NULL input strin");
		return (NULL);
	}
	args = malloc(MAX_TOKEN * sizeof(char *));
	if (args == NULL)
	{
		perror("malloc failed");
		return (NULL);
	}

	token = strtok(string, " \t\n");
	while (token != NULL)
	{
		args[args_count] = _strdup(token);
		if (args[args_count] == NULL)
		{
			perror("strdup failed");
			free_allocation(args);
			return (NULL);
		}
		token = strtok(NULL, " \t\n");
		args_count++;
	}
	args[args_count] = NULL;

	return (args);
}



/**
 * free_allocation - Function to free the mem allocated for an array
 * @args: Array to be free
*/

void free_allocation(char **args)
{
	int i;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args);
}

/**
 * free_two_string - Function to free two strings
 * @first_string: First string to be freed
 * @second_string: Second string to be freed
*/

void free_two_string(char *first_string, char *second_string)
{
	free(first_string);
	free(second_string);
}

/**
 * execute_commands - Function to execute commands
 * @command: Command to execute
 * @argv: First argument while executing
 * @count: Number of time the program is executed
*/
void execute_commands(char **command, int count, char *argv)
{
	pid_t pid;
	int i = 0, status;
	char copy_of_command[BUFFER_SIZE];

	if (command[0] == NULL)
		return;
	else if (access(command[0], F_OK) == 0 || access(command[0], X_OK) == 0)
	{
		pid = fork();
		if (pid < 0)
		{
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execve(*command, command, environ) == -1)
			{
				if (errno == EACCES)
					exit(126);
				exit(1);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
	else
	{
		_print_argv(argv);
		_strcpy(copy_of_command, command[0]);
		message(count);
		while (copy_of_command[i] != '\0')
		{
			_putchar(copy_of_command[i]);
			i++;
		}
		notfound_message();
	}
	count++;
}

