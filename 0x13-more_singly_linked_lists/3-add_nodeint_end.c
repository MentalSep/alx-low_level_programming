#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list.
 *
 * @head: pointer to the head of list
 * @n: integer to add
 *
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new, *lastNode;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head)
	{
		lastNode = *head;
		while (lastNode->next)
			lastNode = lastNode->next;
		lastNode->next = new;
	}
	else
		*head = new;

	return (new);
}
