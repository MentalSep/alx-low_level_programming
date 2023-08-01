#include "lists.h"

/**
 * find_loop_fr - find the node causing the loop
 *
 * @head: head of the list
 *
 * Return: address of the node causing the loop
 */
listint_t *find_loop_fr(listint_t *head)
{
	listint_t *tmp, *end;

	if (head == NULL)
		return (NULL);

	for (end = head->next; end != NULL; end = end->next)
	{
		if (end == end->next)
			return (end);
		for (tmp = head; tmp != end; tmp = tmp->next)
			if (tmp == end->next)
				return (end->next);
	}
	return (NULL);
}

/**
 * free_listint_safe - frees a listint_t list
 *
 * @h: pointer to head o flist
 *
 * Return: size of h
 */
size_t free_listint_safe(listint_t **h)
{
	size_t nodes = 0, flag = 0;
	listint_t *holder, *tmp;

	holder = find_loop_fr(*h);

	while (*h && (*h != holder || !flag))
	{
		nodes++;
		tmp = (*h)->next;
		if (*h == holder && !flag)
		{
			if (holder == holder->next)
			{
				free(*h);
				break;
			}
			nodes++;
			tmp = tmp->next;
			free((*h)->next);
			flag = 1;
		}
		free(*h);
		*h = tmp;
	}
	*h = NULL;

	return (nodes);
}
