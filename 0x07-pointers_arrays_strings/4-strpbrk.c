/**
 * _strpbrk - Searches for a string
 *
 * @s: string to be searched.
 * @accept: The character.
 *
 * Return: Points to the first occurence
 */
char *_strpbrk(char *s, char *accept)
{
char *p = s;

while (*p != '\0')
{
char *q = accept;

while (*q != '\0')
{
if (*p == *q)
{
return (p);
}
q++;
}

p++;
}

return (0);
}
