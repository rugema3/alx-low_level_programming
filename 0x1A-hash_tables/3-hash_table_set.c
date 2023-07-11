#include "hash_tables.h"
/**
 * hash_table_set - Adds or updates a key/value pair in the hash table
 * @ht: The hash table to modify
 * @key: The key string
 * @value: The value associated with the key
 * Return: 1 if succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node, *temp_node;

	/* Check if the hash table and key are valid */
	if (ht == NULL || key == NULL || strlen(key) == 0)
		return (0);
	/* Calculate the index using the key */
	index = key_index((const unsigned char *)key, ht->size);

	/* Check if a node with the same key exists, update its value */
	temp_node = ht->array[index];
	while (temp_node != NULL)
	{
		if (strcmp(temp_node->key, key) == 0)
		{
			free(temp_node->value);
			temp_node->value = strdup(value);
			if (temp_node->value == NULL)
				return (0);
			return (1);
		}
		temp_node = temp_node->next;
	}
	/* Create a new node and add it at the beginning of the list */
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	if (new_node->key == NULL || new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (0);
	}
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}

