#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at the given
 * index in a dlistint_t list
 * @head: Pointer to the pointer to the head of the list
 * @index: Index of the node to delete (starting from 0)
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current_node, *temp;
	unsigned int freq = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	current_node = *head;

	if (index == 0)
	{
		*head = current_node->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current_node);
		return (1);
	}

	while (current_node != NULL && freq < index)
	{
		current_node = current_node->next;
		freq++;
	}

	if (current_node == NULL)
		return (-1);

	temp = current_node->prev;
	temp->next = current_node->next;

	if (current_node->next != NULL)
		current_node->next->prev = temp;

	free(current_node);
	return (1);
}
