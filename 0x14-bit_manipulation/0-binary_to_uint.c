#include <stdlib.h>
#include <stddef.h>
#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: String of characters
 *
 * Return: the converted number, or 0 if there is an invalid char or b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
unsigned int result = 0;

if (b == NULL)
return (0);

for (; *b != '\0'; b++)
{
if (*b != '0' && *b != '1')
return (0);

result = (result << 1) + (*b - '0');
}

return (result);
}
