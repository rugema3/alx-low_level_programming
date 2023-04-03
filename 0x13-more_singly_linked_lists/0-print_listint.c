#include<stdio.h>
#include<stdlib.h>
#include"lists.h"

/**
 * print_listint - the function prints all the elements in a list
 * @h: head(where the nodes begin)
 * Return: number of nodes.
 */
size_t print_listint(const listint_t *h)
{
	int count;

	const listint_t  *ptr = NULL;

	ptr = h;
	count = 0;
	while (ptr != NULL)
	/**
	 * we initialised the pointer ptr to equal to the head.
	 * The head is the begining of the nodes.
	 * I am asuming that the list is not empty initially.
	 *
	 */
	{
		count++;/*we are counting the number of nodes/elements*/
		printf("%d\n", ptr->n);
		/**
		 * Here we are printing the data present
		 * where the pointer points to.
		 */
		ptr = ptr->next; /* ptr points to the next node and updates it*/
	}
	return (count);
}
