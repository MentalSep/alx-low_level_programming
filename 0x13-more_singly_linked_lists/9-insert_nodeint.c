#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 *
 * @head: pointer to head of the list
 * @idx: ndex of the list where the new node should be added
 * @n: integer to add to the new node
 *
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new, *tmp;
	unsigned int i = 0;

	new = malloc(sizeof(listint_t));
	if (!head || !new || !(*head))
		return (NULL);

	tmp = *head;
	while (tmp)
	{
		if (i++ == idx - 1)
		{
			new->n = n;
			new->next = tmp->next;
			tmp->next = new;
			return (new);
		}
		tmp = tmp->next;
	}

	free(new);
	return (NULL);
}
