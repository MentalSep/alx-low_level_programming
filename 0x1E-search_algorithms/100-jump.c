#include "search_algos.h"
#include <math.h>

/**
 * jump_search - Searches for a value in a sorted array using Jump search.
 * @array: A pointer to the first element of the array to search in.
 * @size: The size of the array
 * @value: The value to search for.
 *
 * Return: The first index where the value is located, or -1 if not found.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step = sqrt(size), prev = 0;

	if (!array)
		return (-1);

	while (prev < size && array[prev] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		prev += step;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", prev - step, prev);
	prev -= step;

	while (prev < size && array[prev] <= value)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		if (array[prev] == value)
			return (prev);
		prev++;
	}

	return (-1);
}
