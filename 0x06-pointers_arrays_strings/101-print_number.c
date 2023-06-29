#include "main.h"

/**
 * print_number - prints an integre.
 *
 * @n: integre to print.
 *
 * Return: void
 */
void print_number(int n)
{
	unsigned int i = (n < 0) ? -n : n;

	if (n < 0)
		_putchar('-');
	if (i / 10)
		print_number(i / 10);
	_putchar(i % 10 + '0');
}
