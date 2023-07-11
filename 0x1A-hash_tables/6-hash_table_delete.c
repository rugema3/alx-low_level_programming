#include "hash_tables.h"

/**
 * delete_list_recursive - Recursive function to delete a linked list
 * @node: The current node to delete
 */
void delete_list_recursive(hash_node_t *node)
{
	if (node == NULL)
		return;

	delete_list_recursive(node->next);
	/* Recursively delete the rest of the linked list */

	free(node->key);  /* Free the memory for the key */
	free(node->value);  /* Free the memory for the value */
	free(node);  /* Free the memory for the node */
}

/**
 * hash_table_delete - Deletes a hash table
 * @ht: The hash table to delete
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int index;

	if (ht == NULL)
		return;

	for (index = 0; index < ht->size; index++)
	{
		delete_list_recursive(ht->array[index]);
		/* Delete the linked list at each index */
	}

	free(ht->array);  /* Free the memory for the array */
	free(ht);  /* Free the memory for the hash table structure */
}

