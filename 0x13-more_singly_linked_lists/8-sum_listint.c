#include<stdio.h>
#include<stdlib.h>
#include"lists.h"

/**
 * sum_listint- the function adds all the elements in a list
 * @head: head(where the nodes begin)
 * Return: sum of the elements.
 */
int sum_listint(listint_t *head)
{
	int sum;

	const listint_t  *ptr = NULL;

	ptr = head;
	sum = 0;
	while (ptr != NULL)
	/**
	 * we initialised the pointer ptr to equal to the head.
	 * The head is the begining of the nodes.
	 * I am asuming that the list is not empty initially.
	 *
	 */
	{
		sum = ptr->n + sum;
		ptr = ptr->next; /* ptr points to the next node and updates it*/
	}
	return (sum);
}
