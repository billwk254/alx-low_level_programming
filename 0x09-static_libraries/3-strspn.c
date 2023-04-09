/**
 * _strspn - gets the substring
 * @s: input string
 * @accept: pointer to a string
 *
 * Return: return number of bytes
 */
unsigned int _strspn(char *s, char *accept)
{
unsigned int len = 0;
char *p = accept;

while (*s != '\0')
{
while (*p != '\0' && *p != *s)
{
p++;
}
if (*p == '\0')
{
return (len);
}
len++;
s++;
p = accept;
}

return (len);
}
