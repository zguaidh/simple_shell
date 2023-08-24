#include "main.h"
/**
 *print_error - prints a generic error message with details about the error
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
 * Return: no return
 */
void print_error_exec(void)
{
	print_error();
	_print_err(": ");
	_print_err("not found\n");
}
/**
 * cd_err - handles error printing for cd
 *
 * Return: no return value
 */
void cd_err(void)
{
	_print_err(name_of_program);
	_print_err(": ");
	print_number(count);
	_print_err(": ");
	_print_err(name_of_command);
	_print_err(": can't cd to ");
	_print_err(name_of_dst);
	write(2, "\n", 1);
}
