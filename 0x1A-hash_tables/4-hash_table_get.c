#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key in the hash table
 * @ht: The hash table to search
 * @key: The key string to look for
 *
 * Return: The value associated with the key, or NULL if key couldn't be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *temp_node;

	/* Check if the hash table and key are valid */
	if (ht == NULL || key == NULL || strlen(key) == 0)
		return (NULL);

	/* Calculate the index using the key */
	index = key_index((const unsigned char *)key, ht->size);

	/* Traverse the linked list at the calculated index */
	temp_node = ht->array[index];
	while (temp_node != NULL)
	{
		if (strcmp(temp_node->key, key) == 0)
			return (temp_node->value);
		temp_node = temp_node->next;
	}

	return (NULL); /* Key couldn't be found */
}


