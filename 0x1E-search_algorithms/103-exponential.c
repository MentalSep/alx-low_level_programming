#include "search_algos.h"

/**
 * exponential_search - searches for a value in a sorted array of integers
 * using the Exponential search algorithm
 * @array: pointer to the first elenebt in the array to search in
 * @size: size of the array
 * @value: the value to look for
 *
 * Return: the first index where value is located
*/
int exponential_search(int *array, size_t size, int value)
{
	size_t i = 1, left = 0, right = size - 1, mid;

	if (!array)
		return (-1);

	while (i < size && array[i] < value)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		i *= 2;
	}

	right = i < size ? i : size - 1;
	left = i / 2;

	printf("Value found between indexes [%ld] and [%ld]\n", left, right);

	while (left <= right)
	{
		printf("Searching in array: ");
		for (mid = left; mid < right; mid++)
			printf("%d, ", array[mid]);
		printf("%d\n", array[mid]);

		mid = left + (right - left) / 2;

		if (array[mid] < value)
			left = mid + 1;
		else if (array[mid] > value)
			right = mid - 1;
		else
			return (mid);
	}

	return (-1);
}
