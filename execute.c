#include "main.h"
/**
 *execute - execute a program with the given filename and arguments
 *@filename: the name of the program to execute
 *@av: the array of arguments
 *@env: an array of settings representing the environment variables
 *@count: number of strings of the array of arguments
 *
 *Return: no return
 */

void execute(char *filename, char **av, char **env, int count)
{
	pid_t child_pid;
	int status = 0;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (filename == NULL)
			exit_status = 0;

		if (execve(filename, av, env) == -1)
		{
			print_error_exec(av, filename, count);
			errno = 127;
			exit(errno);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			errno = exit_status;
		}
	}
}

/**
 *exec_from_path - execute a filname considering its path
 *@filename: the name of the program to execute
 *@av: the array of arguments
 *@env: an array of settings representing the environment variables
 *@count: number of strings of the array of arguments
 *
 *Return: no return
 */

void exec_from_path(char *filename, char **av, char **env, int count)
{
	if (access(filename, F_OK) == 0)
	{
		execute(filename, av, env, count);
	}
	else
	{
	/*	filename = path_finder(exec_arg, environ);*/
		execute(filename, av, env, count);
	}
}
