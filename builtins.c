#include "main.h"

/**
 * cd_req - Changes current working directory to specified argument
 *
 * @str: voided parameter string
 * @env: voided parameter env
 * @exec_arg: array of arguments
 *
 * Return: no return value
 */
void cd_req(char *str, char **env, char **exec_arg)
{
	int i = 0;
	char *home_dir = getenv("HOME"), *old_dir = getenv("OLDPWD");
	char cwd[1024];
	(void)str, (void)env;

	if (_strcmp(exec_arg[0], "cd") == 0)
	{
		get_cwd(cwd, sizeof(cwd), "OLDPWD");

		if (exec_arg[1] == NULL || _strcmp(exec_arg[1], "") == 0)
		{
			if (home_dir != NULL)
				i = chdir(home_dir);
		}
		else if (_strcmp(exec_arg[1], "-") == 0)
		{
			if (old_dir != NULL)
			{
				i = chdir(old_dir);
				_print(old_dir), _print("\n");
			}
			else
			{
				i = chdir(getenv("PWD"));
				_print(getenv("PWD")), _print("\n");
			}
		}
		else
			i = chdir(exec_arg[1]);
		if (i != 0)
		{
			name_of_dst = exec_arg[1];
			cd_err();
			exit_status = errno;
		}
		else
		{
			get_cwd(cwd, sizeof(cwd), "PWD");
		}
	}
}
/**
 *exit_req - exit request function
 *@str: a strings that needs to be free
 *@env: an array of strings representing environment variables
 *@args: Arguments
 *
 * Return: no return value
 */

void exit_req(char *str, char **env, char **args)
{
	(void)env;
	(void)args;

	free(str);
	errno = exit_status;
	exit(errno);
}
/**
 *env_req - Environment request function
 *@str: a pointer to a string (not used)
 *@env: an array of strings representing environment variables
 *@args: Arguments
 *
 *Return: no return value
 */

void env_req(char *str, char **env, char **args)
{
	int i, j;
	(void)str;
	(void)args;

	for (i = 0; env[i] != NULL; i++)
	{
		if (env[i] != NULL)
		{
			j = 0;
			while (env[i][j] != '\0')
			{
				write(1, &env[i][j], 1);
				j++;
			}
			write(1, "\n", 1);
		}
	}
}
/**
 *get_b - searches for a builtin command and returns a function pointer
 *to the correspendind built-in function or NULL otherwise
 *@s: a string representing the name of the built-in
 *@env: an array of strings representing environment variables
 *@a: Arguments
 *
 *Return: no return value
 */
void (*get_b(char *s, char **env, char **a))(char *s, char **env, char **a)
{
	builtins builtin[] = {
		{"exit", exit_req},
		{"env", env_req},
		{"cd", cd_req},
		{NULL, NULL}
	};
	int i = 0;
	(void)env;
	(void)a;

	while (builtin[i].built != NULL)
	{
		if (_strcmp(s, builtin[i].built) == 0)
			return (builtin[i].f);
		i++;
	}

	return (NULL);
}
/**
 *_build - build and execute function
 *@exec_arg: an array of strings representing the command and its arguments
 *@buff: a string buffer for a possible usein the built-in function
 *@env: an array of strings representing environment variables
 *
 * Return: no return value
 */

int _build(char **exec_arg, char *buff, char **env)
{
	void (*func)(char *, char **, char **);
	int exit_status;

	func = get_b(exec_arg[0], env, exec_arg);
	if (func == NULL)
		return (-1);
	if (_strcmp("exit", exec_arg[0]) == 0)
	{
		free_contents(exec_arg);
		exit_status = 1;
	}

	func(buff, env, exec_arg);
	return (exit_status);
}
