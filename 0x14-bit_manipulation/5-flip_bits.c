#include "main.h"

/**
 * flip_bits - returns the number of bits you would need
 * to flip to get from one number to another.
 *
 * @n: first number
 * @m: second number
 *
 * Return: the number of bits you would need to flip
 * to get from one number to another
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int i, count = 0;
	unsigned long int diff = n ^ m;

	for (i = 0; i < 64; i++)
		if ((diff >> i) & 1)
			count++;

	return (count);
}
