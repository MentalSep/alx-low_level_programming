#include "main.h"

/**
 * get_prime - checks for prime number recursively.
 *
 * @num: number to check
 * @i: integer
 *
 * Return: 1 if num is a prime number, 0 otherwise
 */
int get_prime(int num, int i)
{
	if (i == num)
		return (1);
	else if (num % i == 0)
		return (0);
	return (get_prime(num, i + 1));
}

/**
 * is_prime_number - checks for prime numbers
 *
 * @n: number to check
 *
 * Return: 1 if n is a prime number, 0 otherwise.
 */
int is_prime_number(int n)
{
	if (n < 2)
		return (0);
	return (get_prime(n, 2));
}
