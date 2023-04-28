#include "lists.h"
#include <stddef.h>
#include <stdio.h>

/**
 * print_list - Prints all the elements of a list_t list.
 * @h: Head node of the list
 *
 * Return: nodes in the list
 */
size_t print_list(const list_t *h)
{
size_t count = 0;

while (h != NULL)
{
if (h->str == NULL)
printf("[%d] (nil)\n", h->len);
else
printf("[%d] %s\n", h->len, h->str);

h = h->next;
count++;
}

return (count);
}
