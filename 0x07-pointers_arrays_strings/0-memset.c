#include "main.h"

/**
 * _memset - fills memory with a constant byte.
 *
 * @s: string to modify.
 * @b: byte to use for filling
 * @n: number of bytes to fill.
 *
 * Return: pointer to s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
