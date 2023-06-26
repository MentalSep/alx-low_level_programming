#include "main.h"

/**
 * print_array - prints n elements of an array of integers,
 * followed by a new line.
 *
 * @a: array of ints
 * @n: number of elemnts to print
 *
 * Return: Void
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		(i != n - 1) ? printf(", ") : 0;
	}
	printf("\n");
}
