#include<stdio.h>
#include"lists.h"
/**
 * insert_nodeint_at_index - this functions adds a new node at a given
 * position.
 * @head: the pointer to the first node.
 * @idx: the index of the list where the new node should be added.
 * @n: position where the node is to be inserted.
 * Return: the address of the new node, or NULL if it failed.
 *
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *ptr1 = *head;
	listint_t *ptr2 = malloc(sizeof(listint_t));

	ptr2->n = idx;
	ptr2->next = NULL;

	n--;
	while (n != 1)
	{
		ptr1 = ptr1->next;
		n--;
	}
	ptr2->next = ptr1->next;
	ptr1->next = ptr2;
	return (ptr2);

}
