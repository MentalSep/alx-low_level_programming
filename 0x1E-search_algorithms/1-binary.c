#include "search_algos.h"

/**
 * print_array - prints the elements in the array
 * @array: array to print
 * @left: the start index
 * @right: the end index
 *
*/
void print_array(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
		printf("%d%s", array[i], i < right ? ", " : "\n");

}
/**
 * binary_search - searches for a value in a sorted array of integers
 * using the Binary search algorithm
 * @array: a pointer to the first element of the array to search in
 * @size: size of the array
 * @value: the value to find
 *
 * Return: the index where value is located
*/
int binary_search(int *array, size_t size, int value)
{
	size_t left = 0, right = size - 1, mid;

	if (!array)
		return (-1);

	/**
	 * printf("Searching in array: ");
	 * for (i = 0; i <= size; i++)
	 *	printf("%d%s", array[i], i < size ? ", " : "\n");
	 */
	print_array(array, 0, right);

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (array[mid] == value)
			return (mid);

		else if (array[mid] > value)
		{
			right = mid - 1;

			if (left <= right)
				print_array(array, 0, right);
			/**
			 * printf("Searching in array: ");
			 * for (i = 0; i <= right; i++)
			 *	printf("%d%s", array[i], i < right ? ", " : "\n");
			 */
		}
		else
		{
			left = mid + 1;

			if (left <= right)
				print_array(array, left, right);
			/**
			 *  printf("Searching in array: ");
			 * for (i = left; i <= right; i++)
			 *	printf("%d%s", array[i], i < right ? ", " : "\n");
			 */
		}
	}
	return (-1);
}
