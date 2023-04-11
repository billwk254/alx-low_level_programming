#include <stdlib.h>
/**
 * create_array - creates an array of chars
 * @size: the size of the array
 * @c: initialization character
 *
 * Return: Pointer to the created array or NULL
 */
char *create_array(unsigned int size, char c)
{
char *arr;
unsigned int i;

if (size == 0)
return (NULL);

arr = malloc(size * sizeof(char));
if (arr == NULL)
return (NULL);

for (i = 0; i < size; i++)
arr[i] = c;

return (arr);
}
