#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: the value to look for
 *
 * Return: the first node where value is located
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = list, *prev = NULL;

	if (!list)
		return (NULL);

	while (current->n < value && current->express)
	{
		prev = current;
		current = current->express;
		printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);
	}

	if (current->n >= value)
		printf("Value found between indexes [%ld] and [%ld]\n",
			prev->index, current->index);
	else
	{
		prev = current;
		while (current->next)
			current = current->next;
		printf("Value found between indexes [%ld] and [%ld]\n",
			prev->index, current->index);
	}

	while (prev)
	{
		printf("Value checked at index [%ld] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}
