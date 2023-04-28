#include "lists.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * free_list - Frees a list_t list
 * @head: List head
 **/
void free_list(list_t *head)
{
list_t *current = head, *next;

while (current != NULL)
{
next = current->next;
free(current->str);
free(current);
current = next;
}
}
