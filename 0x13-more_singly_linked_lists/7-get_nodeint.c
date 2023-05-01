#include "lists.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * get_nodeint_at_index - Returns the nth node of a linked list
 * @head: A pointer to the head of the list
 * @index: The index of the node, starting at 0
 *
 * Return: Nth node of the list
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
unsigned int i;

for (i = 0; head != NULL && i < index; i++)
head = head->next;

return (head == NULL || i < index ? NULL : head);
}
