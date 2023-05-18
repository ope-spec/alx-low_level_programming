#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * struct dlistint_s - Doubly linked list node
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 *
 * Description: This structure represents a node in a doubly linked list.
 * It contains an integer value 'n' and pointers to the previous
 * and next nodes in the list.
 */
typedef struct dlistint_s
{
	int n;
	struct dlistint_s *prev;
	struct dlistint_s *next;
} dlistint_t;

/* Function prototypes */
size_t print_dlistint(const dlistint_t *h);
size_t dlistint_len(const dlistint_t *h);
dlistint_t *add_dnodeint(dlistint_t **head, const int n);
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);
void free_dlistint(dlistint_t *head);
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);
int sum_dlistint(dlistint_t *head);
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);
void create_dlistint_sample(dlistint_t **head);
void test_delete_dnodeint_at_index(dlistint_t **head, unsigned int index);
int generateRandomChar(char *username);
int multiplyChars(char *username, int length);
int findLargestNumber(char *username, int length);




#endif /* LISTS_H */
