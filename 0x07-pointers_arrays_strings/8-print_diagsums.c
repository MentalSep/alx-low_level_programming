#include "main.h"

/**
 * print_diagsums -printsthe sum of two diagonals of
 * a square matrix of integers.
 *
 * @a: pointer to the matrix.
 * @size: size of the matrix.
 *
 * Return: void.
 */
void print_diagsums(int *a, int size)
{
	int i, diagsum1 = 0, diagsum2 = 0;

	for (i = 0; i < size; i++)
	{
		diagsum1 += a[i * (size + 1)];
		diagsum2 += a[(i + 1) * (size - 1)];
	}
	printf("%d, %d\n", diagsum1, diagsum2);
}
