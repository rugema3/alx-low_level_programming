#include"lists.h"
/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the head of the list
 * Return: pointer to the node where the loop starts,
 * or NULL if there is no loop
 **/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise = head, *hare = head;

	/**
	 * Floyd's cycle-finding algorithm.
	 * The idea is to have two pointers moving through the list at
	 * different speeds, with one pointer (the hare) moving faster than
	 * the other (the tortoise). If there is a loop in the list,
	 * the hare will eventually catch up to the tortoise and they will
	 * meet at some node in the loop.
	 */

	/* Step 1: detect the loop */
	while (hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;
		if (tortoise == hare)
			break;
	}

	if (!hare || !hare->next)
		return (NULL); /* no loop */
	/* Step 2: find the start of the loop */
	tortoise = head;
	while (tortoise != hare)
	{
		tortoise = tortoise->next;
		hare = hare->next;
	}
	return (tortoise);
}

