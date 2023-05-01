#include "lists.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * add_nodeint - Adds a new node at the beginning of a list
 * @head: Pointer to pointer to head of list
 * @n: New node integer
 *
 * Return: New element address,Null on failure
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *new_node = malloc(sizeof(listint_t));

if (new_node == NULL)
{
return (NULL);
}

new_node->n = n;
new_node->next = *head;
*head = new_node;

return (new_node);
}
