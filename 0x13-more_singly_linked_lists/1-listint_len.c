#include "lists.h"

/**
 * listint_len -  returns the number of elements in a linked listint_t list.
 *
 * @h: linked list
 *
 * Return: number of elements in h
 */
size_t listint_len(const listint_t *h)
{
	size_t nodes;

	for (nodes = 0; h; nodes++)
		h = h->next;
	return (nodes);
}
