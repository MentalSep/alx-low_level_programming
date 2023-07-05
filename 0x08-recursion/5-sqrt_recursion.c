#include "main.h"

/**
 * get_sqrt - calculates the natural square root of num
 *
 * @num: integer
 * @sqrt: integer
 *
 * Return: the natural square root of num, otherwise -1 if num doesn't have
 * a natural square root.
 */
int get_sqrt(int num, int sqrt)
{
	if (sqrt * sqrt == num)
		return (sqrt);
	if (sqrt * sqrt > num)
		return (-1);
	return (get_sqrt(num, sqrt + 1));
}

/**
 * _sqrt_recursion - returns the naturl square root of a number.
 *
 * @n: integer.
 *
 * Return: the natural square root of n.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (get_sqrt(n, 0));
}
