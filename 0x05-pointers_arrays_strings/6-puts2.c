#include "main.h"

/**
 * puts2 - prints every other character of q string,with the first
 * character, followed by a new line.
 *
 * @str: pointer to string
 *
 * Return: void
 */
void puts2(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		if (i % 2 == 0)
			_putchar(str[i]);
	_putchar('\n');
}
