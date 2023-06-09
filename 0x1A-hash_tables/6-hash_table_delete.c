#include "hash_tables.h"

/**
 * hash_table_delete - Deletes hash table.
 * @ht: A pointer to a hash table.
 * Return: Nothing
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head = ht;
	hash_node_t *current_node, *temp;
	unsigned long int i;

	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			current_node = ht->array[i];
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
