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
 *_strcat - concatenate two strings to create a new string
 *
 *@s1: the first string to be concatenated
 *@s2: the second string to be concatenated
 *
 *Return: a pointer to newly created concatenated string
 */

char *_strcat(char *s1, char *s2)
{
	int a = 0, b = 0;

	while (s1[a] != '\0')
		a++;

	while (s2[b] != '\0')
	{
		s1[a] = s2[b];
		a++;
		b++;
	}

	s1[a] = '\0';

	return (s1);
}
/**
 *print_char - prints a single  character to stdout
 *@c: the character to be printed
 *
 *Return: the number of bytes written
 */

int print_char(char c)
{
	return (write(STDERR_FILENO, &c, 1));
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

char *_strcpy(char *s1, char *s2)
{
	int i = 0;

	s1[i] = s2[i];
	while (s2[i] != '\0')
	{
		i++;
		s1[i] = s2[i];
	}
	return (s1);
}
