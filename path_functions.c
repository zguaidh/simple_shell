#include "main.h"
/**
 *concat_path - concatenate the input with the PATH environment variables
 *
 *@filename: the input to be concatenated
 *
 * Return: a pointer to the concatenated path, or otherwise NULL
 */
char *concat_path(char *filename)
{
	char *path = getenv("PATH");
	char *path_copy, *token, *con_token = NULL;
	char *buff;

	if (path == NULL)
	{
		exit(127);
	}
	path_copy = _strdup(path);
	buff = strtok(path_copy, ":");
	while (buff != NULL)
	{
		token = str_concat(buff, "/");
		con_token = str_concat(token, filename);
		buff = strtok(NULL, ":");
	}

	return (con_token);
}
