#include"lists.h"
#include<stdio.h>

/**
 * print_listint_safe - prints a listint_t linked list safely
 * @head: pointer to the head of the linked list
 * Return: number of nodes in the linked list
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *curr = head;
    const listint_t *next_node = NULL;
    size_t node_count = 0;

    while (curr)
    {
        node_count++;
        printf("[%p] %d\n", (void *)curr, curr->n);
        next_node = curr->next;

        /* check if next node has been visited before */
        if (next_node >= curr)
        {
            printf("-> [%p] %d\n", (void *)next_node, next_node->n);
            printf("Linked list has a cycle\n");
            break;
        }

        curr = next_node;
    }

    return (node_count);
}

