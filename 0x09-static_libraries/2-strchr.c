/**
 * _strchr - locates a character in a string
 * @s: pointer to string
 * @c: char to locate
 *
 * Return: first char to be located
 */
char *_strchr(char *s, char c)
{
while (*s != '\0')
{
if (*s == c)
{
return (s);
}
s++;
}
if (*s == c)
{
return (s);
}
return (0);
}
