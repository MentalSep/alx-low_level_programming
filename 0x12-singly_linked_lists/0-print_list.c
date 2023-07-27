#include "lists.h"

/**
 * print_list - printd all the elements of a list_t list
 *
 * @h: list to print
 *
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		if (h->str)
			printf("[%u] %s\n", h->len, h->str);
		else
			printf("[0] (nil)\n");
		nodes += 1;
		h = h->next;
	}
	return (nodes);
}
