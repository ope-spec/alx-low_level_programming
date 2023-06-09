#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table
 * @size: Size of the array
 * Return: On success, returns a pointer to the newly created hash table
 * On failure, returns NULL
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_hash_table;
	unsigned long int index;

	new_hash_table = malloc(sizeof(hash_table_t));
	if (new_hash_table == NULL)
		return (NULL);

	new_hash_table->array = malloc(sizeof(hash_node_t *) * size);
	if (new_hash_table->array == NULL)
	{
		free(new_hash_table);
		return (NULL);
	}

	new_hash_table->size = size;

	for (index = 0; index < size; index++)
	{
		new_hash_table->array[index] = NULL;
	}

	return (new_hash_table);
}
