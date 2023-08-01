#include "lists.h"

/**
 * find_loop_ - find the node causing the loop
 * 
 * @head: head of the list
 *
 * Return: address of the node causing the loop
 */
listint_t *find_loop(listint_t *head)
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
 * print_listint_safe - prints a listint_t linked list
 *
 * @head: pointer to head of list
 *
 * Return: the number of nodes in the lsit
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes = 0, flag = 0;
	listint_t *holder;

	holder = find_loop((listint_t *) head);

	while (head && (head != holder || !flag))
	{
		printf("[%p] %d\n", (void *)head, head->n);
		if (head == holder)
			flag = 1;
		head = head->next;
		nodes++;
	}

	if (holder)
		printf("-> [%p] %d\n", (void *)head, head->n);
	
	return (nodes);
}
