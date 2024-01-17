#include "search_algos.h"

/**
 * helper - performs the advanced binary search
 * @array: a pointer to the first element of the array to search in
 * @left: the leftmost index
 * @right: the rightmost index
 * @value: the value to find
 *
 * Return: the index where value is located
*/
int helper(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (left > right)
		return (-1);

	printf("Searching in array: ");
	for (mid = left; mid < right; mid++)
		printf("%d, ", array[mid]);
	printf("%d\n", array[mid]);

	mid = left + (right - left) / 2;

	if (array[mid] == value && array[mid - 1] != value)
		return (mid);
	else if (array[mid] >= value)
		return (helper(array, left, mid, value));
	else
		return (helper(array, mid + 1, right, value));
}

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * using the Binary search algorithm and recursion
 * @array: a pointer to the first element of the array to search in
 * @size: size of the array
 * @value: the value to find
 *
 * Return: the index where value is located
*/
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);

	return (helper(array, 0, size - 1, value));
}
