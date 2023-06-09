#include "hash_tables.h"

/**
 * key_index - Get the index of a key/value pair
 * in the hash table's array.
 * @key: The key to retrieve the index for.
 * @size: The size of the array in the hash table.
 *
 * Return: The index of the key within the array.
 *
 * Description: This function uses the djb2 algorithm to calculate the index
 * at which a key/value pair should be stored in the hash table's array.
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
