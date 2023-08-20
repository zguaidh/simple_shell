#include "main.h"
/**
 *concat_path - concatenate the input with the PATH environment variables
 *
 *@filename: the input to be concatenated
 *
 * Return: a pointer to the concatenated path, or otherwise NULL
 */
char **get_path_directories(char **environ)
{
	char *path = NULL, **directories = NULL;
	char *path_copy, *buff;
	int i;

	directories = malloc(sizeof(char *) * 50);
	if (directories ==NULL)
		return (NULL);

	i = 0;
	while (environ[i] != NULL)
	{
		if (strstr(environ[i], "PATH") != NULL && environ[i][4] == '=')
		{
			path = environ[i];
			break;
		}
		i++;
	}

	i = 0;
	while (path[i] != '\0')
		printf("before: %c\n", path[i++]);

	for (i = 0; i < 5; i++)
	{
		path++;
	}

	printf("after: %s\n", path);

	i = 0;
	buff = strtok(path, ":");
	while (buff != NULL)
	{
		directories[i] = strdup(buff);
		buff = strtok(NULL, ":");
		i++;
	}
	if (directories[0] == NULL)
		i++;

	directories[i] = NULL;

	i = 0;
	while (directories[i] != NULL)
	{
		printf("Before:\n%d\t%s\n", i, directories[i]);
		i++;
	}

	return (directories);
}

int find_in_path(char **args, char **argv, char **environ)
{
	char **path_arr = get_path_directories(environ), *full_p = NULL;
	int i = 0, len = 0;
	pid_t pid;

	/*
	while (path_arr[i] != NULL)
	{
		printf("Before concat: %s\n", path_arr[i]);
		i++;
	}*/

	while (path_arr[i] != NULL)
	{
		len = strlen(path_arr[i]) + strlen(args[0]) + 2;
		full_p = malloc(len);
		strcpy(full_p, path_arr[i]);
		strcat(full_p, "/");
		strcat(full_p, args[0]);
		if (access(full_p, F_OK) != -1)
			break;
		i++;
		free(full_p);
	}

	printf("After:\n%s\n", full_p);
	if (full_p == NULL)
		return (-1);

	pid = fork();
	if (pid < 0)
	{
		perror(argv[0]);
		exit(errno);
	}
	else if (pid == 0)
	{
		if (execve(full_p, args, environ) == -1)
		{
			perror(argv[0]);
			return (1);
		}
	}
	else
	{
		wait(NULL);
	}
	return (1);
}

char **split_input(char *input)
{
	char **tokens, *delim = "\n\t";
	char *tok;
	int i = 0;

	tokens = malloc(sizeof(char *) * 50);

	tok = strtok(input, delim);
	while (tok != NULL)
	{
		tokens[i] = strdup(tok);
		tok = strtok(NULL, delim);
		i++;
	}

	if (tokens[0] == NULL)
	{
		i++;
	}

	tokens[i] = NULL;

	return (tokens);
}

int main(int ac, char **av)
{
	char *buff = NULL, *prt = "$ ", **args = NULL;
	size_t buff_len = 0;
	ssize_t read;

	while (1)
	{
		write(1, prt, 2);

		read = getline(&buff, &buff_len, stdin);
		if (read == -1)
		{
			free(buff);
			exit(errno);
		}

		args = split_input(buff);

		if (find_in_path(args, av, environ) == 1)
		{
			continue;
		}
	}

	return (0);
}
