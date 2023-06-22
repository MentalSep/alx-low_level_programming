#include "main.h"

/**
 * main -  program that finds and prints the largest prime factor
 * of the number 612852475143, followed by a new line.
 *
 * Return: always 0.
 */
int main(void)
{
	long int i, n = 612852475143;

	for (i = 2; i < n; i++)
		while (n % i == 0)
			n /= i;
	printf("%ld\n", n);
	return (0);
}
