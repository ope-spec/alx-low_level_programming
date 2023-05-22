#include "lists.h"

/**
 * print_listint - prints all the elements of a linked list
 * @head: head of the list
 *
 * Return: the number of nodes
 */
size_t print_listint(const listint_t *head)
{
    const listint_t *current = head;
    size_t count = 0;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        count++;
        current = current->next;
    }

    return count;
}
