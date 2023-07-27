#include "lists.h"

/**
 * list_len - returns the number of elements in a linked list
 *
 * @h: linked list
 *
 * Return: returns the number of elements in h
 */
size_t list_len(const list_t *h)
{
	size_t nodes;

	for (nodes = 0; h; nodes++)
		h = h->next;
	return (nodes);
}
