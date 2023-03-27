#include "main.h"

/**
 * rev_string - reverses a string
 * @s: char to check
 *
 * Return: 0 rs success
 */

void rev_string(char *s)
{
int i = 0, j, c;
char d;

while (s[i] != '\0')
{
i++;
}
c = i - 1;
for (j = 0; c >= 0 && j < c; c--, j++)
{
d = s[j];
s[j] = s[c];
s[c] = d;
}
}
