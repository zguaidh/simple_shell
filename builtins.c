#include "main.h"
/**
 *exit_req - exit request function
 *@str: a strings that needs to be free
 *
 *Return: no return value
 */

void exit_req(char *str)
{
	free(str);
	errno = exit_status;
	exit(errno);
}
/**
 *env_req - Environment request function
 *@str: a pointer to a string (not used)
 *
 *Return: no return value
 */

void env_req(char *str)
{
	int i, j;
	(void)str;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
			write(1, &environ[i][j], 1);

		write(1, "\n", 1);
	}
}
/**
 *get_builtins - searches for a builtin command and returns a function pointer
 *to the correspendind built-in function or NULL otherwise
 *@str: a string representing the name of the built-in
 *
 *Return: no return value
 */
void (*get_builtins(char *str))(char *str)
{
	builtins builtin[] = {
		{"exit", exit_req},
		{"env", env_req},
		{NULL, NULL}
	};
	int i = 0;

	while (builtin[i].built != NULL)
	{
		if (_strcmp(str, builtin[i].built) == 0)
			return (builtin[i].f);
		i++;
	}
	return (NULL);
}
/**
 *_build - build and execute function
 *@exec_arg: an array of strings representing the command and its arguments
 *@buff: a string buffer for a possible usein the built-in function
 *Return: no return value
 */

int _build(char **exec_arg, char *buff)
{
	void (*func)(char *);
	int exit_status;

	func = get_builtins(exec_arg[0]);
	if (func == NULL)
		return (-1);
	if (_strcmp("exit", exec_arg[0]) == 0)
	{
		free_contents(exec_arg);
		exit_status = 1;
	}

	func(buff);
	return (exit_status);
}
