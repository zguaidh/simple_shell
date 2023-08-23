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

extern char **environ;

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
	void (*f)(char *, char **);
} builtins;

/* Main functions */

int _stat(char *filename);
void tokenize(char *str, char *delim);
char **copy_token(char *str, char *delim);
int num_tokens(char **str);
char *name_of_program;
char *name_of_command;
int count;
int exit_status;
void execute(char *filename, char **exec_arg);
void exec_from_path(char **exec_arg);
char *concat_path(char **exec_arg);
void free_contents(char **str);
char *concat_path(char **exec_arg);
char **get_path(void);

/* Builtins */

void exit_req(char *str, char **env);
void env_req(char *str, char **env);
void (*get_builtins(char *str, char **env))(char *str, char **env);
int _build(char **exec_arg, char *buff, char **env);

/* Helper functions */

void _print(char *str);
void _print_err(char *str);
int print_char(char c);
int _strlen(char *str);
char *_strdup(char *str);
char *_strcat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *s1, char *s2);
char *_strstr(char *haystack, char *needle);
int print_number(int n);

/* Error printing */
void print_error(void);
void print_error_exec(void);

#endif
