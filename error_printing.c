#include "main.h"
/**
 *print_error - prints a generic error message with details about the error
 *
 * Return: no return
 */
void print_error(void)
{

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
 *Return: no return
 */
void print_error_exec(void)
{
	print_error();
	_print_err(": ");
	_print_err("not found\n");
}
