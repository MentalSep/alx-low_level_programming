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
	const listint_t *holder = NULL, *end, *ptr;
	size_t nodes = 0, flag = 0;

	if (!head)
		return (98);
	for (end = head->next; end; end = end->next)
	{
		if (end == end->next)
		{
			holder = end;
			break;
		}
		for (ptr = head; ptr != end; ptr = ptr->next)
		{
			if (ptr == end->next)
			{
				holder = end->next;
				break;
			}
		}
		if (holder)
			break;
	}

	while (head && (head != holder || !flag))
	{
		printf("[%p] %d\n", (void *)head, head->n);
		if (head == holder)
			flag = 1;

		head = head->next;
		nodes++;
	}
	if (holder)
		printf("-> [%p] %d\n", (void *)holder, holder->n);

	return (nodes);
}


