#include "lists.h"

/**
 * listint_len - counts the number of nodes in a linked list
 * @h: head of the list
 *
 * Return: the number of elements
 */
size_t listint_len(const listint_t *head)
{
	const listint_t *curr_node = head;
	size_t count = 0;

	while (curr_node != NULL)
	{
		count += 1;
		curr_node = curr_node->next;
	}
	return (count);
}
