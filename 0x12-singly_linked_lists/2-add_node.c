#include "lists.h"
#include <string.h>

/**
 * add_node - adds a new node at the beginning of a list_t list.
 *
 * @head: pointer to head of the list
 * @str: string to duplicate
 *
 * Return: the address of the new element,
 * or NULL if it failed str needs to be duplicated
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
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

	new->next = *head;
	*head = new;

	return (new);
}
