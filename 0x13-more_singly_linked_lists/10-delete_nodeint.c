#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index index
 * of a listint_t linked list.
 *
 * @head: pointer to head of list
 * @index: he index of the node that should be deleted.
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *tmp, *holder;
	unsigned int i = 0;

	if (!head || !(*head))
		return (-1);

	tmp = *head;
	if (index == 0)
	{
		*head = (*head)->next;
		free(tmp);
		return (1);
	}

	while (tmp)
	{
		if (i++ == index - 1)
		{
			holder = tmp->next;
			tmp->next = holder->next;
			free(holder);
			return (1);
		}
		tmp = tmp->next;
	}

	return (-1);
}
