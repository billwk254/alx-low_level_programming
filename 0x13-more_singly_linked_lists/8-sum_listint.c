#include "lists.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * sum_listint - Returns the sum of all the data of a linked list
 * @head: A pointer to the head of the list
 *
 * Return: Sum of data in the list, zero if null
 */
int sum_listint(listint_t *head)
{
int sum = 0;

while (head != NULL)
{
sum += head->n;
head = head->next;
}

return (sum);
}
