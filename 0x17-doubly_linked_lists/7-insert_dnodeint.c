#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position
 * in a dlistint_t linked list
 * @h: Double pointer to the head of the list
 * @idx: Index where the new node should be added
 * @n: Data value of the new node
 *
 * Return: Address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	if (h == NULL || idx > dlistint_len(*h))
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	if (*h == NULL)
		return (NULL);

	(*h)->next = insert_dnodeint_at_index(&((*h)->next), idx - 1, n);
	if ((*h)->next != NULL)
		(*h)->next->prev = *h;

	return (*h);
}

