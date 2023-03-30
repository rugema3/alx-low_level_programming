#include<stdlib.h>
#include"lists.h"

/**
 * free_list - frees a singly linked list of list_t nodes.
 * @head: pointer to the first node of the list.
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->str);
		free(temp);
	}
}

