#ifndef SHELL_H
#define SHELL_H

/**Header files*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/**Macro environ variable and MAX_TOKEN*/
extern char **environ;
#define MAX_TOKEN 100
#define MAX_DIGITS 20
#define MAX_COMMAND_LENGTH 100
#define BUFFER_SIZE (MAX_COMMAND_LENGTH + 1)

/**Helper functions */
unsigned int _strlen(const char *string);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *original_string);
char *_strncat(char *dest, char *src, int n);
int _putchar(char c);
char *_strcpy(char *dest, const char *src);
void _print_number(int number);
char *_strchr(char *s, char c);
char *_strcat(char *dest, const char *src);
unsigned int _strspn(char *s, char *accept);
int _atoi(char *s);

/**Shell Function*/
void free_allocation(char **args);
char *_getenv(const char *name);
char **tokenize_string(char *string);
void display_prompt(void);
void execute_commands(char **command, int count, char *argv);
void message(int count);
void notfound_message(void);
void _print_argv(char *string);
int _search_path_and_ex(char *input, int i, char *argv);
char *_search_path(char *input);
void exit_function(char *input, char *argv);
int build_int_function_management(char *input, int count, char *argv);
void process_interrative_mode(char *argv[]);
void process_non_interrative_mode(char *argv[]);
void print_env(void);
char *remove_comments(char *input);
int command_separators(char *input, int count, char *argv);
char **tokenize_separator_string(char *string);
char *handle_malloc_faillure(char *string);
int fms(char *one, char *two, char *three, char **a, char **b, char *c, int d);
void free_two_string(char *first_string, char *second_string);
void my_execute(char *string, int count, char *argv);
int check_for_semi_column(char *string, char *argv, int count);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strtok(char *str, char *delim);
char **tokenize_string_for_exit(char *string);
void print_message_for_exit(char *argv, int count, char *input);
void functions(char **com, int count, char *argv, char **antoine, char *first);
int tail_of_comments(char **args, char *c_in, char *s_c_in);
int exit_shell(char *input, char *argv, int count);
void free_5memory(char **antoine, char **args, char *s_c_in, char *c_in);
void allocate_and_tok(char *input, char **s_c_in, char **c_in, char ***args);
void fre_mem1(char *argv, int count, char **args, char *copy_of_a1, char *copy_of_input, char *input);
void fre_mem2(char *argv, int count, char **args, char *copy_of_a1, char *cop);
void free_me3(char **args, char *input, char *copy_of_a1);
void free_mem4(char **args, char *copy_of_a1);
void initialize_exit_shell_variables(char *input, char ***args, char **copy);
void concatTwostrings(const char *str1, const char *str2, char *result);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
void manange_set_and_unset(char **args);
void change_current_working_dir(char **args, char *argv, int count);
void message_error_for_cd(char *args, char *argv, int count);
void manage_back_directory(char *path);
void execute_commands_n(char **command, int count, char *argv);
void int_to_string(int num, char *str);
void sigint_handler(int sig);


#endif


