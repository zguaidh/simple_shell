

#include "main.h"
/**
 *get_path - extractes path directories from the path envirnmnt variable
 *
 *@environ: an array of strings representing the envirenmnt variables
 *
 * Return: an array of strings containing individual pathdirectories
 */
char **get_path(char **environ)
{
	char *path = NULL;
	char *token, **path_directories = NULL;
	char *buff = NULL;
	int  i = 0;

	path_directories = malloc(sizeof(char *) * 1024);
	if (path_directories == NULL)
	{
		perror("Memory allocation failed");
		return (NULL);
	}
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strstr(environ[i], "PATH") != NULL && environ[i][4] == '=')
		{
			path = environ[i];
			break;
		}
	}

	i = 0;
	while (i < 5)
	{
		path++;
		i++;
	}

	buff = strtok(path, ":");
	i = 0;
	while (buff != NULL)
	{
		path_directories[i] = buff;
		buff = strtok(NULL, ":");
		i++;
	}
	if (path_directories[0] == NULL)
		i++;
	path_directories[i] = NULL;
	return (path_directories);
}
/**
 *path_finder - Searches for the full path of an executable
 *within specified directories.
 *
 *@exec_arg: the execubale arguments
 *@environ: the environment variables
 *
 *Return: a string containing the full path to the executable
 */
char *path_finder(char **exec_arg, char **environ)
{
	char **array_path = get_path(environ);
	char *file_path = NULL;
	int len = 0, i = 0;

	printf("Before\n");

	for (i = 0; array_path[i] != NULL; i++)
	{
		len = strlen(exec_arg[0]) + strlen(array_path[i]) + 2;
		file_path = malloc(len);
		strcpy(file_path, array_path[i]);
		strcat(file_path, "/");
		strcat(file_path, exec_arg[0]);
		printf("file_path inside:%s\n", file_path);

		if (access(file_path, F_OK) != -1)
			break;
		free(file_path);
	}
	printf("Command found: %s\n", file_path);

	return (file_path);
}
