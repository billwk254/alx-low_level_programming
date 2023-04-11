#include <stdlib.h>

/**
 * _strdup - returns a pointer to another allocated space in memory
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string or NULL on failure
 */
char *_strdup(char *str)
{
char *dup_str;
int i, len;

if (str == NULL)
return (NULL);

len = 0;
while (str[len] != '\0')
len++;

dup_str = malloc((len + 1) * sizeof(char));
if (dup_str == NULL)
return (NULL);

for (i = 0; i <= len; i++)
dup_str[i] = str[i];

return (dup_str);
}
