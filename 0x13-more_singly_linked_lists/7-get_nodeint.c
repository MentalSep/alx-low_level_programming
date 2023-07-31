#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 *
 * @head: head of list
 * @index: index of the node to return
 *
 * Return: address of the node number index in the list
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (!head)
		return (NULL);

	while (head)
	{
		if (i++ == index)
			return (head);
		head = head->next;
	}

	return (NULL);
}
