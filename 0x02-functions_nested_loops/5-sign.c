#include "main.h"

/**
 * print_sign - prints sign of anumber
 *
 * @n: number to check
 *
 * Return: 1 if n is greater than zero, 0 if n is zero,
 * -1 if n is less than zero
 */
int print_sign(int n)
{
	_putchar((n > 0) ? '+' : (n < 0) ? '+' : '0');
	return ((n > 0) ? 1 : (n < 0) ? -1 : 0);
}
