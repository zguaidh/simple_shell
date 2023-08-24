#include "main.h"

/**
 * get_cwd - sets environment specified by var
 *
 * @str: buffer where environment will be set
 * @size: size of the the buffer
 * @var: variable name to be set a value at
 *
 * Return: no return value
 */
void get_cwd(char *str, size_t size, char *var)
{
	if (getcwd(str, size) != NULL)
		setenv(var, str, 1);
	else
	{
		perror("getcwd");
		exit_status = 1;
	}
}
