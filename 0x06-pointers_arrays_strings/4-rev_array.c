#include "main.h"

/**
 * reverse_array - reverses the content of an array pf integers.
 *
 * @a: array of ints.
 * @n: number of element of the array.
 *
 * Reutur: void
 */

void reverse_array(int *a, int n)
{
	int i, j, tmp;

	for (i = 0, j = n - 1; i < j; i++, j--)
	{
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
}
