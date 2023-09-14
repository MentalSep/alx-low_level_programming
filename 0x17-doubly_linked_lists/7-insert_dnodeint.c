#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to the head of the list
 * @idx: index of the list where the new node should be added
 * @n: data to insert in the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *node, *tmp;

	if (!h)
		return (NULL);
	if (!idx)
		return (add_dnodeint(h, n));
	tmp = *h;
	while (--idx && tmp)
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	if (!tmp->next)
		return (add_dnodeint_end(h, n));
	node = malloc(sizeof(dlistint_t));
	if (!node)
		return (NULL);
	node->n = n;
	node->prev = tmp;
	node->next = tmp->next;
	tmp->next->prev = node;
	tmp->next = node;

	return (node);
}
