#include "main.h"

/**
 * flip_bits - returns the number of bits you would need
 * to flip to get from one number to another.
 *
 * @n: first number
 * @m: second number
 *
 * Return: the number of bits you would need
 * to flip to get from one number to another
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count = 0;

	for (; n || m; m >>= 1, n >>= 1)
		if ((n & 1) != (m & 1))
			count++;

	return (count);
}
