/**
 * wildcmp - compares two strings
 * identical, otherwise return 0. s2 can contain the special character *.
 * The special char * can replace any string
 * @s1: the first string
 * @s2: the second string
 *
 * Return: 1 if the strings are identical, 0 otherwise.
 */
int wildcmp(char *s1, char *s2)
{
if (*s2 == '*')
{
if (*(s2 + 1) == '\0')
return (1);
if (*s1 == '\0')
return (wildcmp(s1, s2 + 1));
return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
}
else if (*s1 == '\0')
{
return (*s2 == '\0');
}
else
{
return ((*s1 == *s2) && wildcmp(s1 + 1, s2 + 1));
}
}
