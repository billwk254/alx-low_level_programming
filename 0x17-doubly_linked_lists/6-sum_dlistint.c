#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * sum_dlistint - Returns the sum of all data in a doubly linked list
 * @head: Pointer to the head of the list
 *
 * Return: The sum of all data, or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
int sum = 0;
dlistint_t *current = head;

while (current != NULL)
{
sum += current->n;
current = current->next;
}

return (sum);
}
