#include "lists.h"

/**
 * free_list - frees a linked list
 * @head: pointer to the head of the linked list
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *current_node;

	while ((current_node = head) != NULL)
	{
		head = head->next;
		free(current_node->str);
		free(current_node);
	}
}
