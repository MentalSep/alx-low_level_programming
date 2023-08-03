#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index
 *
 * @n: number
 * @index: index of the bit to change
 *
 * Return: 1 on success, 0 if an error occured
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 64)
		return (-1);

	*n |= 1ul << index;
	return (1);
}
