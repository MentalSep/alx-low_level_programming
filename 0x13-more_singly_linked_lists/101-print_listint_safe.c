#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list
 *
 * @head: pointer to head of list
 *
 * Return: the number of nodes in the lsit
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *tmp, *holder;
	size_t nodes;

	if (!head)
		return(98);

	tmp = head;
	for (nodes = 0; tmp; nodes++)
	{
		holder = tmp;
		tmp = tmp->next;
		printf("[%p] %d\n", (void *)holder, holder->n);

		if (holder < tmp)
		{
			printf("-> [%p] %d\n", (void *)tmp, tmp->n);
			return (++nodes);
		}
	}

	return (nodes);
}
