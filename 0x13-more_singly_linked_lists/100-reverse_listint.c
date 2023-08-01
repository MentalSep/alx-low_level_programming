#include "lists.h"

/**
 * reverse_listint - revreses a listint_t linke list
 *
 * @head: pointer to head of list
 *
 * Return: pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *tmp, *next;

	if (!head || !(*head))
		return (NULL);

	tmp = NULL;
	while (*head)
	{
		next = (*head)->next;
		(*head)->next = tmp;
		tmp = *head;
		*head = next;
	}
	*head = tmp;

	return (*head);
}
