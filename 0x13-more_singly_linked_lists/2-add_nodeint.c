#include<stdio.h>
#include<stdlib.h>
#include"lists.h"

/**
 * add_nodeint - the function prints all the elements in a list
 * @head: head(where the nodes begin)
 * @n: value to be stored in a new node
 * Return: address of the new element, or NULL
 */
listint_t *add_nodeint(listint_t **head, const int n)
{

	listint_t  *newnode = malloc(sizeof(listint_t));

	if (newnode == NULL)
		return (NULL);
	/* Initializing the new node */

	newnode->n = n;


	newnode->next = *head;

	/* Updating the head pointer to point to the new node */
	*head = newnode;

	return (*head);
}
