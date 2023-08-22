#include "main.h"

/**
 * get_path - retrieve directories from the PATH environment
 *
 * Return: an array of strings containing the directories from the PATH
 */
char **get_path(void)
{
	char *path = getenv("PATH"), *token, **path_directories = NULL;
	char *buff = NULL;
	int i = 0;

	if (path == NULL)
	{
		print_error_exec();
		exit_status = 127;
		exit(exit_status);
	}
	path_directories = malloc(sizeof(char *) * 50);
	if (path_directories == NULL)
	{
		perror("Memory allocation failed");
		return (NULL);
	}
	while (environ[i] != NULL)
	{
		if (strstr(environ[i], "PATH") != NULL && environ[i][4] == '=')
		{
			path = environ[i];
			break;
		}
		i++;
	}
	for (i = 0; i < 5; i++)
		path++;
	token  = _strdup(path);
	buff = strtok(token, ":");
	i = 0;
	while (buff != NULL)
	{
		path_directories[i] = _strdup(buff);
		buff = strtok(NULL, ":");
		i++;
	}
	if (path_directories[0] == NULL)
		i++;
	path_directories[i] = NULL;
	return (path_directories);
}
/**
 *concat_path - concatenate the input with the PATH environment variables
 *
 *@exec_arg: the input to be concatenated
 *
 * Return: a pointer to the concatenated path, or otherwise NULL
 */
char *concat_path(char **exec_arg)
{
	char **path = get_path();
	char *file_path = NULL;
	int i = 0, len = 0;

	for (i = 0; path[i]; i++)
	{
		len = _strlen(exec_arg[0]) + _strlen(path[i]) + 2;
		file_path = malloc(len * sizeof(char *));
		_strcpy(file_path, path[i]);
		_strcat(file_path, "/");
		_strcat(file_path, exec_arg[0]);
		if (access(file_path, F_OK) != -1)
			break;
		free(file_path);
	}

	return (file_path);
}
