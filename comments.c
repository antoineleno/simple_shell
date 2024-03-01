#include "shell.h"
/**
 * remove_comments - function that replaces the first instance of '#' with null
 * @input: Input of the user
 *
 * Return: Always 0;
 */
char *remove_comments(char *input)
{
char pid_str[20];
char *pid_pos;
char *status_pos;
char *comment_pos;
char *processed_input;
int len;
processed_input = _strdup(input);

pid_pos = strstr(processed_input, "$$");
if (pid_pos != NULL)
{
snprintf(pid_str, sizeof(pid_str), "%d", getpid());
strcpy(pid_pos, pid_str);
}
status_pos = strstr(processed_input, "$?");
if (status_pos != NULL)
{
char count_str[20];
sprintf(count_str, "%d", 10);
strcpy(status_pos, count_str);
}

comment_pos = _strchr(processed_input, '#');
if (comment_pos != NULL)
{
*comment_pos = '\0';
}

len = strlen(processed_input);
while (len > 0 && (processed_input[len - 1] == ' '
|| processed_input[len - 1] == '\t' || processed_input[len - 1] == '\n'))
{
processed_input[--len] = '\0';
}
return (processed_input);
}

/**
 * command_separators - Function that mange t
 * @count: The count for the loop
 * @argv: First argument enter by the user
 * @input: Input of the user
 * Return: The flag
*/
int command_separators(char *input, int count, char *argv)
{
	char **args, *c_in, **command_with_path = NULL;
	char *s_c_in, madeleine[1024], **antoine;
	int i = 0, flag = 0, is_Semi_Column = 0, s_flag = 0;


	is_Semi_Column = check_for_semi_column(input, argv, count);
	if (is_Semi_Column == 1)
	{
		allocate_and_tok(input, &s_c_in, &c_in, &args);
		while (args[i] != NULL)
		{
			strcpy(madeleine, args[i]);
			antoine = tokenize_string(madeleine);
			if (antoine[0] == NULL)
			{
				free_5memory(antoine, args, s_c_in, c_in);
				return (1);
			}
			if (_strchr(antoine[0], '/') == NULL)
			{
				s_flag = fms(input, c_in, s_c_in, antoine, args, argv, count);
				if (s_flag == 0)
				{
					my_execute(args[i], count, argv);
					free_allocation(antoine);
				}
				else
				{
					free_allocation(antoine);
				}
			}
			else
			{
				functions(command_with_path, count, argv, antoine, args[i]);
			}
			i++;
		}
		flag = tail_of_comments(args, c_in, s_c_in);
	}
	return (flag);
}

/**
 * allocate_and_tok - Function to reduce line in comments
 * @input: INput
 * @s_c_in: First input to deine
 * @c_in: Second_intput to define
 * @args: Tokenize value
*/

void allocate_and_tok(char *input, char **s_c_in, char **c_in, char ***args)
{
	*s_c_in = malloc(_strlen(input) + 1);
	handle_malloc_faillure(*s_c_in);
	_strcpy(*s_c_in, input);
	*c_in = malloc(_strlen(input) + 1);
	handle_malloc_faillure(*c_in);
	_strcpy(*c_in, input);
	*args = tokenize_separator_string(*c_in);
}



/**
 * tokenize_separator_string - Function to tokenize a string base one ;
 * @string: String to be tokenize
 * Return: The tokenize string
*/
char **tokenize_separator_string(char *string)
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

	token = strtok(string, ";");
	while (token != NULL)
	{
		args[args_count] = _strdup(token);
		if (args[args_count] == NULL)
		{
			perror("strdup failed");
			free_allocation(args);
			return (NULL);
		}
		token = strtok(NULL, ";");
		args_count++;
	}
	args[args_count] = NULL;

	return (args);
}



