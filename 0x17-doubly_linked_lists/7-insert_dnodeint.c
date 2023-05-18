#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node
 * at a given position in a dlistint_t list
 * @h: Pointer to the pointer to the head of the list
 * @idx: Index of the position where the new node
 * should be added (starting from 0)
 * @n: Data for the new node
 *
 * Return: The address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *current_node;
	unsigned int freq = 0;

	if (h == NULL)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;

	if (idx == 0)
	{
		new_node->prev = NULL;
		new_node->next = *h;
		if (*h != NULL)
			(*h)->prev = new_node;
		*h = new_node;
		return (new_node);
	}

	current_node = *h;
	while (current_node != NULL && freq < idx - 1)
	{
		current_node = current_node->next;
		freq++;
	}

	if (current_node == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->prev = current_node;
	new_node->next = current_node->next;
	if (current_node->next != NULL)
		current_node->next->prev = new_node;
	current_node->next = new_node;
	return (new_node);
}
