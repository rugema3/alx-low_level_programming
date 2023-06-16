#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given
 * index in a dlistint_t linked list
 * @head: Double pointer to the head of the list
 * @index: Index of the node to be deleted
 *
 * Return: 1 if deletion succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		dlistint_t *temp = *head;
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	return (delete_dnodeint_at_index_recursive(head, index));
}

/**
 * delete_dnodeint_at_index_recursive - Recursive function to delete
 * the node at a given index
 * @head: Double pointer to the head of the list
 * @index: Index of the node to be deleted
 *
 * Return: 1 if deletion succeeded, -1 if it failed
 */
int delete_dnodeint_at_index_recursive(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i;
	dlistint_t *next;

	if (*head == NULL)
		return (-1);

	/*dlistint_t *current;*/
	/*unsigned int i;*/

	if (index == 0)
	{
		dlistint_t *temp = *head;
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	current = *head;
	for (i = 0; i < index - 1 && current != NULL; i++)
	{
		current = current->next;
	}

	if (current == NULL || current->next == NULL)
		return (-1);

	next = current->next;
	current->next = next->next;
	if (next->next != NULL)
		next->next->prev = current;
	free(next);
	return (1);
}

