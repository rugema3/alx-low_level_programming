#include"lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: pointer to the head node of the list.
 * @index: index of the node to be returned, starting at 0.
 *
 * Return: pointer to the nth node of the list, or
 * NULL if the node does not exist.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;
	listint_t *current_node = head;

	for (i = 0; i < index && current_node != NULL; i++)
		current_node = current_node->next;
	return (current_node);
}

