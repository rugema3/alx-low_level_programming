#include"lists.h"
#include<stdlib.h>

/**
 * free_listint_safe - Frees a listint_t list.
 *
 * @h: Double pointer to the head of the linked list.
 *
 * Return: The number of nodes in the freed list.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *temp;

	while (*h != NULL)
	{
		if (*h <= (*h)->next) /* Check for loop condition */
		{
			/* Free the remaining nodes and set head to NULL */
			free(*h);
			*h = NULL;
			count++;
			return (count);
		}
		/* Store the current node */
		temp = *h;
		/* Move head to next node */
		*h = (*h)->next;
		/* Free current node */
		free(temp);
		count++;
	}
	return (count);
}

