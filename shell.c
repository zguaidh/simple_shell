#include "main.h"
/**
 *main - entry point
 *Description: program that simulates an interactive shell
 *@ac: the num of command-line arguments passed to the program
 *@av: an array of strings representing command-line arguments
 *@env: an array of strings representing environment variables
 *
 *Return: an integer
 */


int main(int ac, char **av, char **env)
{
	char *buff = NULL, *prompt = ":) ", **exec_arg = NULL;
	ssize_t read;
	size_t buff_len = 0;
	int i = 0;
	bool interactive = isatty(STDIN_FILENO);
	(void)ac;
	(void)env;

	while (1)
	{
		if (interactive == 1)
			_print(prompt);
		read = getline(&buff, &buff_len, stdin);
		if (read != -1)
		{
			exec_arg = copy_token(buff, " \n\t");
			if (exec_arg[0] == NULL)
			{
				free_contents(exec_arg);
				continue;
			}
			count += num_tokens(exec_arg);
			name_of_program = av[0];
			name_of_command = exec_arg[0];
			i = _build(exec_arg, buff, env);
			if (i == -1)
			{
				exec_from_path(exec_arg);
			}
			free_contents(exec_arg);
		}
		else
			exit_req(buff, env, exec_arg);
	}
	return (0);
}
