#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer to a hash table.
 *
 * Description: This function frees the memory allocated for the
 * given hash table and all its nodes.
 */
void hash_table_delete(hash_table_t *ht)
{
	if (ht == NULL)
		return;

	hash_table_t *head = ht;
	hash_node_t *current_node, *temp;
	unsigned long int index;

	for (index = 0; index < ht->size; index++)
	{
		if (ht->array[index] != NULL)
		{
			current_node = ht->array[index];
			while (current_node != NULL)
			{
				temp = current_node->next;
				free(current_node->key);
				free(current_node->value);
				free(current_node);
				current_node = temp;
			}
		}
	}

	free(head->array);
	free(head);
}
