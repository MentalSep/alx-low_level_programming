#include "main.h"

/**
 * puts_half - prints half of a string, followed by a new line
 *
 * @str: pointer to string
 *
 * Return: void
 */
void puts_half(char *str)
{
	int i = 0, n;

	while (str[i])
		i++;
	n = (i % 2 == 0) ? i / 2 : (i + 1) / 2;
	for (; str[n]; n++)
		_putchar(str[n]);
	_putchar('\n');
}
