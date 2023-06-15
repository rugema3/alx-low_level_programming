#include "lists.h"

/**
 * sum_dlistint - Returns the sum of all the data
 * values in a dlistint_t linked list
 * @head: Pointer to the head of the list
 *
 * Return: Sum of all the data values, or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	if (head == NULL)
		return (0);

	return (head->n + sum_dlistint(head->next));
}

