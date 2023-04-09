/**
 * _strstr - Substring locator
 *
 * @haystack: The string 
 * @needle: substring
 *
 * Return: If a substring is found return it to the
 * first pointer of the occurence
 */
char *_strstr(char *haystack, char *needle)
{
char *p = haystack;
char *q = needle;

while (*p != '\0')
{
if (*p == *q)
{
char *r = p;
while (*r == *q && *r != '\0' && *q != '\0')
{
r++;
q++;
}
if (*q == '\0')
{
return (p);
}
else
{
q = needle;
}
}
p++;
}

return (0);
}
