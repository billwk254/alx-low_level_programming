#include "lists.h"
#include <stddef.h>
#include <stdio.h>

/**
 * listint_len - Returns the number of elements in a linked list
 * @h: Head pointer to list
 *
 * Return: Number of list elements
 */
size_t listint_len(const listint_t *h)
{
size_t num_elements = 0;
const listint_t *current = h;

while (current != NULL)
{
num_elements++;
current = current->next;
}

return (num_elements);
}
