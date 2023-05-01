#include "lists.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * insert_nodeint_at_index - Inserts a new node at a given position
 * @head: A pointer to the head of the list
 * @idx: New list index
 * @n: New node value
 *
 * Return: New node address
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
listint_t *new_node, *prev_node, *current_node;
unsigned int i;

if (head == NULL)
return (NULL);

new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);
new_node->n = n;

if (idx == 0)
{
new_node->next = *head;
*head = new_node;
}
else
{
prev_node = NULL;
current_node = *head;
for (i = 0; i < idx && current_node != NULL; i++)
{
prev_node = current_node;
current_node = current_node->next;
}

if (i != idx)
{
free(new_node);
return (NULL);
}

prev_node->next = new_node;
new_node->next = current_node;
}

return (new_node);
}
