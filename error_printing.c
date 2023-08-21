#include "main.h"
/**
 *print_error - prints a generic error message with details about the error
 *@arg: the command and its arguments
 *@prompt: the name of the program
 *@count: the number of tokens in the arg array
 *
 * Return: no return
 */
void print_error(char **arg, char *prompt, int count)
{
	(void)arg;
	(void)prompt;

	_print_err(name_of_program);
	_print_err(": ");
	print_number(count);
	/*write(STDERR_FILENO, count, 1);*/
	_print_err(": ");
	_print_err(name_of_command);
}
/**
 *print_error_exec - prints an error message for a command execution failure
 *
 *@arg: the command and its arguments
 *@command: the name of the command that failed to execute
 *@count: the number of tokens in the arg array
 *
 * Return: no return
 */
void print_error_exec(char **arg, char *command, int count)
{
	print_error(arg, command, count);
	_print_err(": ");
	_print_err("not found\n");
}
