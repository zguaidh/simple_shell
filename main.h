#ifndef MAIN_H_
#define MAIN_H_

/* Header files */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

/* MACRO */

char *name_of_program;
char *name_of_command;
extern char **environ;
int exit_status;

/* Structures */

/**
 * struct builtins - structure that finds the char in built
 * and returns function *f
 *
 * @built: character to be found
 * @f: function to be returned
 */
typedef struct builtins
{
	char *built;
	void (*f)(char *);
} builtins;

/* Main functions */

int _stat(char *filename);
void tokenize(char *str, char *delim);
char **copy_token(char *str, char *delim);
int num_tokens(char **str);
void execute(char *filename, char **av, char **env, int count);
void exec_from_path(char *filename, char **av, char **env, int count);
char *concat_path(char *filename);
void free_contents(char **str);

/* Builtins */

void exit_req(char *str);
void env_req(char *str);
void (*get_builtins(char *str))(char *str);
int _build(char **exec_arg, char *buff);

/* Helper functions */

void _print(char *str);
void _print_err(char *str);
int print_char(char c);
int _strlen(char *str);
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
char *_strstr(char *haystack, char *needle);
int print_number(int n);

/* Error printing */
void print_error(char **arg, char *prompt, int count);
void print_error_exec(char **arg, char *command, int count);

#endif
