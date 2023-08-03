#include "main.h"

/**
 * binary_to_uint - converts a binary number to an
 * unsigned int
 *
 * @b: pointer to string of 0 and 1 chars
 *
 * Return: the converted number, or 0 if fail
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int n, i;

	for (n = 0, i = 0; b && b[i]; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		n += b[i] - '0';
		if (b[i + 1])
			n <<= 1;
	}

	return (n);
}
