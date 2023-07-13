#include "main.h"

/**
 * array_range - creates an array of integers
 *
 * @min: start of the range
 * @max: end of range
 *
 * Return: pointer to the array, NULL if it fails
 */
int *array_range(int min, int max)
{
	int i;
	int *range;

	if (min > max)
		return (NULL);

	range = malloc(sizeof(int) * (max - min + 1));
	if (!range)
		return (NULL);

	for (i = 0; i <= max - min; i++)
		range[i] = min + i;

	return (range);
}
