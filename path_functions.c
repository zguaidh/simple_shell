#include "main.h"
/**
 *concat_path - concatenate the input with the PATH environment variables
 *
 *@filename: the input to be concatenated
 *
 * Return: a pointer to the concatenated path, or otherwise NULL
 */
char **get_path(char **environ)
{
	char *path = NULL;
	char *token, **path_directories = NULL;
	char *buff = NULL;
	int  i = 0;

	path_directories = malloc(sizeof(char *) * 50);
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
	{
		i++;
	}

	path_directories[i] = NULL;

	return (path_directories);
}

char *path_finder(char **exec_arg, char **av, char **environ)
{
	char **array_path, *file_path = NULL;
	int len = 0, i = 0;

	array_path = get_path(environ);

	for (i = 0; array_path[i] != NULL; i++)
	{
		len = strlen(exec_arg[0]) + strlen(array_path[i]) + 2;
		file_path = malloc(len);
		strcpy(file_path, array_path[i]);
		strcat(file_path, "/");
		strcat(file_path, exec_arg[0]);
		if (access(file_path, F_OK) != -1)
			break;
		free(file_path);
	}
	printf("Command found: %s\n", file_path);

	return (file_path);
}

int main(int ac, char **av, char **environ)
{
	char **exec_arg = NULL;
	int i = 0;

	if (ac < 2)
	{
		printf("Enter argument\n");
	}

	path_finder(exec_arg, av, environ);

	return (0);

}
