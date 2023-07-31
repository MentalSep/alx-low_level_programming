#include "lists.h"

/**
 * print_listint - prints all the elements of a lisint_t list
 *
 * @h: list to print
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t nodes;

	for (nodes = 0; h; nodes++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (nodes);
}
