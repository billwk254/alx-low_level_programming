#include "main.h"

/**
 * string_toupper - a function to change all the lowercase
 * string characters to uppercase
 * @n: pointer
 *
 * Return: the uppercased string
 */

char *string_toupper(char *n)
{
int i;

i = 0;

while (n[i] != '\0')
{
if (n[i] >= 'a' && n[i] <= 'z')
n[i] = n[i] - 32;
i++;
}
return (n);
}
