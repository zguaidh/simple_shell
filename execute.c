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

void execute(char *filename, char **exec_arg, int count)
{
	pid_t child_pid;
	int status = 0;

	if (filename == NULL)
		exit_status == 0;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(filename, exec_arg, environ) == -1)
		{
			print_error_exec(exec_arg, filename, count);
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

void exec_from_path(char **exec_arg, int count)
{

	if (access(exec_arg[0], F_OK) == 0)
		execute(exec_arg[0], exec_arg, count);
	else
		execute(concat_path(exec_arg), exec_arg, count);
}
