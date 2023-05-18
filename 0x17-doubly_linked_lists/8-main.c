#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* create_dlistint_sample - Create a sample dlistint_t linked list
* @head: Pointer to the head of the list
*/
void create_dlistint_sample(dlistint_t **head)
{
	add_dnodeint_end(head, 0);
	add_dnodeint_end(head, 1);
	add_dnodeint_end(head, 2);
	add_dnodeint_end(head, 3);
	add_dnodeint_end(head, 4);
	add_dnodeint_end(head, 98);
	add_dnodeint_end(head, 402);
	add_dnodeint_end(head, 1024);
}

/**
* test_delete_dnodeint_at_index - Test the delete_dnodeint_at_index function
* @head: Pointer to the head of the list
* @index: Index of the node to delete
*/
void test_delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	printf("-----------------\n");
	delete_dnodeint_at_index(head, index);
	print_dlistint(*head);
}

/**
* main - Check the code
*
* Return: Always EXIT_SUCCESS
*/
int main(void)
{
	dlistint_t *head = NULL;

	create_dlistint_sample(&head);
	print_dlistint(head);

	test_delete_dnodeint_at_index(&head, 5);
	test_delete_dnodeint_at_index(&head, 0);
	test_delete_dnodeint_at_index(&head, 0);
	test_delete_dnodeint_at_index(&head, 0);
	test_delete_dnodeint_at_index(&head, 0);
	test_delete_dnodeint_at_index(&head, 0);
	test_delete_dnodeint_at_index(&head, 0);
	test_delete_dnodeint_at_index(&head, 0);
	test_delete_dnodeint_at_index(&head, 0);
	test_delete_dnodeint_at_index(&head, 0);
	test_delete_dnodeint_at_index(&head, 0);
	test_delete_dnodeint_at_index(&head, 0);
	test_delete_dnodeint_at_index(&head, 0);
	test_delete_dnodeint_at_index(&head, 0);
	test_delete_dnodeint_at_index(&head, 0);
	test_delete_dnodeint_at_index(&head, 0);
	test_delete_dnodeint_at_index(&head, 0);

	return (0);
}
