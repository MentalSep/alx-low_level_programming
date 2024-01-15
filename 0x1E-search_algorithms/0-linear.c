#include "search_algos.h"

/**
 * linear_search - searches for a value in an array of integers using
 * the Linear search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: size of tyhe array
 * @value: the value to look for
 *
 * Return: the first index where value is found
*/
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (!array)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (array[i] == value)
		{
			printf("Value checked array[%ld] = [%d]\n", i, array[i]);
			return (i);
		}
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);

	}
	return (-1);
}
