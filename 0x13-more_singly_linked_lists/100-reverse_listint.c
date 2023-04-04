#include"lists.h"
/**
 * reverse_listint - Reverses a linked list of integers
 * @head: Pointer to the pointer to the head of the list
 *
 * Return: Pointer to the new head of the list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *next;

	while (*head != NULL)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}

	return (prev);
}

