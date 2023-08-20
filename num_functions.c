#include "main.h"
/**
 * print_number - prints numbers
 * @n: the integer to be printed
 *
 * Return: integer
 */

int print_number(int n)
{
	unsigned int x;
	int count, div;

	x = n;
	count = 0, div = 1;

	while (x / div > 9)
		div *= 10;

	while (div != 0)
	{
		count += print_char('0' + x / div);
		x %= div;
		div /= 10;
	}
	return (count);
}
