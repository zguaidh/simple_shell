#include "main.h"
/**
 *_stat - checks if a specified file exists
 *and can be accesed using stat function
 *
 *@filename: the name of the file to be checked
 *
 * Return: 0 on success or 1 if it fails
 */
int _stat(char *filename)
{
	struct stat st;

	if (stat(filename, &st) == 0)
		return (0);
	else
		return (1);
}
/**
 *tokenize - tokenize a string with a specified delimiter
 *
 *@str: the input string to be tokenized
 *@delim: the delimiter used for tokenization
 *
 * Return: no return
 */
void tokenize(char *str, char *delim)
{
	char *token;

	token = strtok(str, delim);
	while (token != NULL)
		token = strtok(NULL, delim);
}
/**
 *copy_token - tokenize a string and copy tokens into an array of strings
 *
 *@str: the input string to be tokenized
 *@delim: the delimiter used for tokenization
 *
 * Return: an array of strings containing the copied tokens
 */
char **copy_token(char *str, char *delim)
{
	int count = 0;
	char *buff_arg, **exec_arg;

	exec_arg = malloc((_strlen(str) / 2 + 2) * sizeof(char *));
	if (exec_arg == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	buff_arg = strtok(str, delim);
	while (buff_arg != NULL)
	{
		exec_arg[count] = _strdup(buff_arg);
		count++;
		buff_arg = strtok(NULL, delim);
	}
	exec_arg[count] = NULL;

	return (exec_arg);
}
/**
 *num_tokens - count number of tokens in an array of strings
 *
 *@str: an array of strings terminated by NULL pointer
 *
 *Return: number of tokens in the array
 */
int num_tokens(char **str)
{
	int count = 0;

	while (str[count] != NULL)
	{
		count++;
	}

	return (count);
}
