#include "hash_tables.h"

/**
 * hash_table_set - Add or update an element in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to add - key cannot be an empty string.
 * @keyValue: The value associated with key.
 *
 * Return: On success, returns 1. On failure, returns 0.
 *
 * Description: This function adds or updates an element in the hash table.
 * If the key already exists in the hash table, the function updates its value
 * with the new value provided.
 * If the key does not exist, the function creates a new node with
 * the given key-value pair and adds it to the appropriate index
 * in the hash table's array using the key's hash value.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *keyValue)
{
    hash_node_t *new_node;
    char *value_copy;
    unsigned long int index, i;

    if (ht == NULL || key == NULL || *key == '\0' || keyValue == NULL)
        return (0);

    value_copy = strdup(keyValue);
    if (value_copy == NULL)
        return (0);

    index = key_index((const unsigned char *)key, ht->size);
    for (i = index; ht->array[i]; i++)
    {
        if (strcmp(ht->array[i]->key, key) == 0)
        {
            free(ht->array[i]->value);
            ht->array[i]->value = value_copy;
            return (1);
        }
    }

    new_node = malloc(sizeof(hash_node_t));
    if (new_node == NULL)
    {
        free(value_copy);
        return (0);
    }

    new_node->key = strdup(key);
    if (new_node->key == NULL)
    {
        free(new_node);
        return (0);
    }

    new_node->value = value_copy;
    new_node->next = ht->array[index];
    ht->array[index] = new_node;
    return (1);
}
