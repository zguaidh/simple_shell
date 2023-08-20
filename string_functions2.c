#include "main.h"

/**
 *_strstr - locate a substring withing a string
 *
 *@haystack: the string to be searched
 *@needle: the sbstring to be located
 *
 *Return: a pointer to the first occurence of the sbstring or otherwise NULL
 */

char *_strstr(char *haystack, char *needle)
{
	int i, j;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (haystack[i + j] != needle[j])
				break;
		}
		if (!needle[j])
			return (&haystack[i]);
	}
	return (NULL);
}

/**
 *str_concat - concatenate two strings to create a new string
 *
 *@s1: the first string to be concatenated
 *@s2: the second string to be concatenated
 *
 *Return: a pointer to newly created concatenated string
 */

char *str_concat(char *s1, char *s2)
{
	char *result;
	int i, j, len1, len2, len;

	len1 = len2 = 0;
	if (s1 != NULL)
	{
		i = 0;
		while (s1[i++] != '\0')
			len1++;
	}
	if (s2 != NULL)
	{
		i = 0;
		while (s2[i++] != '\0')
			len2++;
	}

	len = len1 + len2;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		result[i] = s1[i];

	for (j = 0; j < len2; j++, i++)
	result[i] = s2[j];

	result[len] = '\0';
	return (result);
}
/**
 *print_char - prints a single  character to stdout
 *@c: the character to be printed
 *
 *Return: the number of bytes written
 */

int print_char(char c)
{
	return (write(1, &c, 1));
}
/**
 *_print_err - prints Error message to the stdout
 *@str: a string containing the error message
 *
 * Return: no return value
 */
void _print_err(char *str)
{
	write(STDERR_FILENO, str, _strlen(str));
}
