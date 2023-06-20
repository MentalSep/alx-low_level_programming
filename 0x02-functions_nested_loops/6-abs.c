#include "main.h"

/**
 * _abs - computes the absolute value of integer
 *
 * @n: number to check
 *
 * Return: n if the integer is greater than zero,
 * -n if the integer is less than zero
 */
int _abs(int n)
{
	return ((n < 0) ? -n : n);
}
