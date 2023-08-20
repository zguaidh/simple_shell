#include "main.h"
/**
 *_strlen - calculate the length of a string
 *
 *@str: the input string
 *
 * Return: the length of the given string
 */
int _strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 *_print - print a string to the stdout
 *
 *@str: the input string
 *
 * Return: no return
 */
void _print(char *str)
{
	write(1, str, _strlen(str));
}
/**
 *_strdup - duplicate a string using dynamic memory allocation
 *
 *@str: the input string
 *
 *Return: a pointer to the newly duplicated string or NULL
 */
char *_strdup(char *str)
{
	char *c;
	int i, len;

	if (str == NULL)
		return (NULL);
	len = 0;
	while (str[len] != '\0')
		len++;
	c = (char *)malloc((sizeof(char) * len) + 1);
	if (c == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		c[i] = str[i];
	c[len] = '\0';
	return (c);
}
/**
 *_strcmp - compare two strings lexicographically
 *
 *@s1: the first string for comparison
 *@s2: the second string for comparison
 *
 *Return: 0 if s1 is equal to S2, positive int if s1 is greater than s2
 *or negative value if s1 is less than s2
 */
int _strcmp(char *s1, char *s2)
{
	int i;
	int results;

	for (i = 0; s1[i] == s2[i]; i++)
	{
		if (s1[i] == '\0')
		{
			return (0);
		}
	}
	results = s1[i] - s2[i];

	return (results);
}
