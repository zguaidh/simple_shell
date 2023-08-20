#include "main.h"

/**
 *free_contents - free memory associated with  array of strings
 *
 * @str: the input array of strings to be freed
 * Return: no return
 */

void free_contents(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
