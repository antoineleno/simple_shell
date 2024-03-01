#include "shell.h"

/**
 * execute_commands_n - Function to execute commands
 * @command: Command to execute
 * @argv: First argument while executing
 * @count: Number of time the program is executed
*/
void execute_commands_n(char **command, int count, char *argv)
{
	pid_t pid;
	int i = 0, status;
	char error_message[1024], number[20];

	if (command[0] == NULL)
	{
		return;
	}
	else if (access(command[0], F_OK) == 0 && access(command[0], X_OK) == 0)
	{
		pid = fork();
		if (pid < 0)
		{
			perror("Error\n");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execve(*command, command, environ);
			exit(127);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
	else
	{
		int_to_string(count, number);
		_strcpy(error_message, argv);
		_strcat(error_message, ": ");
		_strcat(error_message, number);
		_strcat(error_message, ": ");
		_strcat(error_message, command[0]);
		_strcat(error_message, ": not found\n");
		write(STDERR_FILENO, error_message, _strlen(error_message));
		i++;
		exit(127);
	}
	count++;
}

/**
 * int_to_string - convert int to string
 * @num: integer to convert
 * @str: string to store the result
*/
void int_to_string(int num, char *str)
{
int i = 0, j;
int len;
int is_negative = 0;
char temp;

if (num < 0)
{
is_negative = 1;
num = -num;
}
do {
str[i++] = num % 10 + '0';
num /= 10;
} while (num > 0);
if (is_negative)
{
str[i++] = '-';
}
len = i;
for (j = 0; j < len / 2; j++)
{
temp = str[j];
str[j] = str[len - j - 1];
str[len - j - 1] = temp;
}
str[i] = '\0';
}

