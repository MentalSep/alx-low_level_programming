#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list,
 * and returns the head node’s data (n).
 *
 * @head: pointer to head of list
 *
 * Return: the head nodes's data (n)
 */
int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int n;

	if (!head || !(*head))
		return (0);

	tmp = *head;
	n = tmp->n;

	*head = (*head)->next;
	free(tmp);

	return (n);
}
