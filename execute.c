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

void execute(char *filename, char **exec_arg)
{
	pid_t child_pid;
	int status = 0;

	if (filename == NULL)
	{
		exit_status = 0;
	}

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(filename, exec_arg, environ) == -1)
		{
			if (access(filename, X_OK) != 0)
			{
				print_error_exec();
				errno = 127;
				free_contents(exec_arg);
				exit(errno);
			}
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

void exec_from_path(char **exec_arg)
{
	char *filename;

	filename = concat_path(exec_arg);
	if (access(exec_arg[0], F_OK) == 0)
		execute(exec_arg[0], exec_arg);
	else
		execute(filename, exec_arg);

}
