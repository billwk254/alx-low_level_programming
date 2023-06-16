#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given index
 * @head: Pointer to a pointer to the head of the list
 * @index: Index of the node to be deleted
 *
 * Return: 1 if deletion succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *temp, *current = *head;
unsigned int count = 0;

if (*head == NULL)
return (-1);

if (index == 0)
{
*head = current->next;
if (*head != NULL)
(*head)->prev = NULL;
free(current);
return (1);
}

while (count < index)
{
if (current == NULL)
return (-1);

current = current->next;
count++;
}

if (current == NULL)
return (-1);

temp = current->prev;
temp->next = current->next;
if (current->next != NULL)
current->next->prev = temp;
free(current);

return (1);
}
