#include<stdio.h>
#include<stdlib.h>
#include"lists.h"

/**
 * listint_len - the function returns the number of elements in a list
 * @h: head(where the nodes begin)
 * Return: number of nodes which is the same as number of elements.
 */
size_t listint_len(const listint_t *h)
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
		/*printf("%d\n", ptr->n);*/
		ptr = ptr->next; /* ptr points to the next node and updates it*/
	}
	return (count);
}
