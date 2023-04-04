/**
 * _memset - fills memory with a constant byte
 * @s: first character
 * @b: second character
 * @n: int to fill bytes
 *
 * Return: pointer s
 */
char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;
for (i = 0; i < n; i++)
{
s[i] = b;
}
return (s);
}

