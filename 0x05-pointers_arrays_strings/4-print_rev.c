#include "main.h"

/**
 * print_rev - prints a string. in reverse, followed by a new line, to stdout.
 *
 * @s: pointer to string
 *
 * Return: void
 */
void print_rev(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	while (i)
		_putchar(s[--i]);
	_putchar('\n');
}
