#include "variadic_functions.h"

/**
 * sum_them_all - calculates sum of all its parameters
 *
 * @n: number of parameters
 *
 * Return: sum of all its parameters.
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	unsigned int  i, s = 0;

	if (!n)
		return (0);

	va_start(args, n);
	for (i = 0; i < n; i++)
		s += va_arg(args, int);
	va_end(args);

	return (s);
}
