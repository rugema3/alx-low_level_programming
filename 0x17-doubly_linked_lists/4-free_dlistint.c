#include "lists.h"

/**
 * free_dlistint - Frees a dlistint_t list
 * @head: Pointer to the head of the list
 *
 * Return: void
 */
void free_dlistint(dlistint_t *head)
{
	if (head == NULL)
		return;
	/*If current node is NULL, there're no more nodes to free, so return*/

	free_dlistint(head->next);
	/* Recursively call the function with the next node */

	free(head); /* Free the memory allocated for the current node */
}

