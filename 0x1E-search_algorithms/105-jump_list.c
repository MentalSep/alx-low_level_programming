#include "search_algos.h"

/**
 * jump_list - searches for a value in a sorted list of integers
 * using the Jump search algorithm
 * @list: pointer to the head of the list to search in
 * @size: size of the list
 * @value: the value to look for
 *
 * Return: the first node where value is located
*/
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t i = 0, j = 0, step = sqrt(size);
	listint_t *current = list, *prev = NULL;

	if (!list)
		return (NULL);

	while (current->n < value && current->next)
	{
		prev = current;
		for (j = 0; j < step && current->next; j++)
			current = current->next;
		printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
		prev->index, current->index);

	for (i = prev->index; i <= current->index && prev; i++)
	{
		printf("Value checked at index [%ld] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}

	return (NULL);
}
