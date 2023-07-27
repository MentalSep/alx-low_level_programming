#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list.
 *
 * @head: head of the linked list
 * @str: str to duplicate
 *
 * Return: the address of the new element,
 * or NULL if it failed str needs to be duplicated
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *lastNode;
	unsigned int len;

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	new->str = strdup(str);
	if (!str)
	{	free(new);
		return (NULL);
	}

	for (len = 0; str[len]; len++)
		;
	new->len = len;

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
