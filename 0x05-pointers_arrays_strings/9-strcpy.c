#include "main.h"

/**
 * _strcpy - copy the string pointed to by scr
 * @dest: destination
 * @src: source
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
int count;

for (count = 0; src[count] != '\0'; count++)
dest[count] = src[count];
dest[count] = '\0';

return (dest);
}
