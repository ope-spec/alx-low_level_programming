#include "./hash_tables.h"

/**
 * hash_table_print - Prints a hash table.
 * @ht: A pointer to the hash table to print.
 *
 * Description: Key/value pairs are printed in the order
 * they appear in the array of the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned char print_del = 0;
	unsigned long int index;

	if (ht == NULL)
		return;

	printf("{");

	for (index = 0; index < ht->size; index++)
	{
		hash_node_t *current_node = ht->array[index];

		while (current_node != NULL)
		{
			if (print_del == 1)
				printf(", ");
			printf("'%s': '%s'", current_node->key, current_node->value);
			print_del = 1;
			current_node = current_node->next;
		}
	}

	printf("}\n");
}
