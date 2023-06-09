#include "hash_tables.h"

/**
 * hash_table_get - Retrieve the value associated with a key in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to retrieve the value of.
 *
 * Return: If the key is not found - NULL.
 *         Otherwise - the value associated with the key in the hash table.
 *
 * Description: This function retrieves the value associated with the given key
 * from the hash table.
 * If the key is found,it returns the corresponding value.
 * If the key is not found, it returns NULL.
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *current_node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	current_node = ht->array[index];
	while (current_node && strcmp(current_node->key, key) != 0)
		current_node = current_node->next;

	if (current_node != NULL)
	{
		return (current_node->value);
	}
	else
		{
			return (NULL);
		}

}
