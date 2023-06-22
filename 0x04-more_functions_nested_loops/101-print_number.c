#include "main.h"

/**
 * print_number - prints integers
 *
 * @n: integer to print
 *
 * Return: void.
 */
void print_number(int n)
{
	unsigned int i = n;

	if (n < 0)
	{
		i = n * -1;
		_putchar('-');
	}
	if (i > 9)
		print_number(i / 10);
	_putchar((i % 10) + '0');
}
