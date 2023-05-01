#include "lists.h"
#include <stddef.h>
#include <stdlib.h>
/**
 * delete_nodeint_at_index - deletes the node at index
 * @head: double pointer to the head node of the linked list
 * @index: Node index
 * Return: 1 if successful, -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *current, *prev;
unsigned int i;

if (*head == NULL)
return (-1);

current = *head;

if (index == 0)
{
*head = (*head)->next;
free(current);
return (1);
}

prev = *head;

for (i = 0; i < index && current != NULL; i++)
{
prev = current;
current = current->next;
}

if (current == NULL)
return (-1);

prev->next = current->next;
free(current);

return (1);
}
