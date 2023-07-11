#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table
 * @ht: The hash table to print
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int index;
	hash_node_t *node;
	int printed = 0;

	/* Check if the hash table is valid */
	if (ht == NULL)
		return;

	printf("{");
	for (index = 0; index < ht->size; index++)
	{
		node = ht->array[index];
		while (node != NULL)
		{
			if (printed == 1)
				printf(", ");
			/**
			 * Print comma and space before each key/value
			 * pair, except the first one
			 */
			printf("'%s': '%s'", node->key, node->value);
			/* Print the key and value */

			printed = 1;
			/* Set printed to 1 after printing the first key/value pair */

			node = node->next;  /* Move to the next node in the linked list */
		}
	}
	printf("}\n");
}

