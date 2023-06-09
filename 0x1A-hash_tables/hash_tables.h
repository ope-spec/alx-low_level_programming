#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/**
 * struct hash_node_s - Node of a hash table
 * @key: The unique identifier for the node
 * @value: The data associated with the key
 * @next: A pointer to the next node in case of collisions
 *
 * Description: This structure represents a node in a hash table. Each node
 * stores a key-value pair and contains a pointer to the next node to handle
 * collisions using chaining.
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 * @size: The size of the array
 * @array: An array of size @size
 *
 * Description: This structure represents a hash table.
 * It consists of an array of size @size, where each cell is a
 * pointer to the first node of a linked list.
 * The linked list is used for handling collisions using chaining.
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;


/**
 * struct shash_node_s - Node of a sorted hash table
 * @key: The unique key associated with the node
 * @value: The value corresponding to the key
 * @next: A pointer to the next node of the list
 * @sprev: A pointer to the previous node in the sorted linked list
 * @snext: A pointer to the next node in the sorted linked list
 *
 * Description: This structure represents a node in a sorted hash table.
 * Each node contains a key-value pair and pointers to the next and previous
 * nodes for the standard linked list functionality. Additionally, it includes
 * pointers to the previous and next nodes for the sorted linked list
 * to maintain the sorted order of elements.
 */
typedef struct shash_node_s
{
	char *key;
	char *value;
	struct shash_node_s *next;
	struct shash_node_s *sprev;
	struct shash_node_s *snext;
} shash_node_t;


/**
 * struct shash_table_s - Sorted hash table data structure
 * @size: The size of the array
 * @array: An array of size @size.
 * Each cell of this array is a pointer to the first node of a linked list.
 * The linked list is used for collision handling with chaining.
 * @shead: A pointer to the first element of the sorted linked list.
 * @stail: A pointer to the last element of the sorted linked list.
 *
 * Description: This structure represents a sorted hash table.
 * It contains an array of size @size, where each cell of the array is a
 * pointer to the first node of a linked list.
 */
typedef struct shash_table_s
{
	unsigned long int size;
	shash_node_t **array;
	shash_node_t *shead;
	shash_node_t *stail;
} shash_table_t;


hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *keyValue);
char *hash_table_get(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);


#endif /* HASH_TABLES_H */
