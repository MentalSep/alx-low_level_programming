#include "main.h"

/**
 * _puts - returns the length of a string
 *
 * @str: pointer to string
 *
 * Return: void
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i])
		_putchar(str[i++]);
	_putchar('\n');
}
