#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.h"
/**
 * strtow - splits a string into words
 * @str: the string to split
 * Return: pointer to array of strings (words), NULL if str is NULL or ""
 */
char **strtow(char *str)
{
if (str == NULL || *str == '\0')
return (NULL);

char **words = NULL;
int i, j, k, len, num_words = 0;

for (i = 0; str[i] != '\0'; i++)
{
if (!isspace(str[i]) && (i == 0 || isspace(str[i - 1])))
num_words++;
}

words = malloc((num_words + 1) * sizeof(char *));
if (words == NULL)
return (NULL);

i = 0;
k = 0;
while (str[i] != '\0')
{
while (isspace(str[i]))
i++;

if (str[i] == '\0')
break;

len = 0;
for (j = i; str[j] != '\0' && !isspace(str[j]); j++)
len++;

words[k] = malloc((len + 1) * sizeof(char));
if (words[k] == NULL)
{
for (j = 0; j < k; j++)
free(words[j]);
free(words);
return (NULL);
}

for (j = 0; j < len; j++)
words[k][j] = str[i + j];
words[k][len] = '\0';
k++;

i += len;
}

words[k] = NULL;

return (words);
}
