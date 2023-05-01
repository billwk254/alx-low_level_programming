#include "lists.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * free_listint2 - Frees a list and sets the head to NULL
 * @head: A pointer to a pointer to the head of the list
 */
void free_listint2(listint_t **head)
{
listint_t *current;

while (*head != NULL)
{
current = *head;
*head = (*head)->next;
free(current);
}

*head = NULL;
}
