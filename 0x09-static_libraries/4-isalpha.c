#include "main.h"

/**
 * _isalpha - checks for alphabetic characters
 * @c:Ascii value
 * Return: 1 if c is a letter, uppercase or lowercase and 0 otherwise
 */
int _isalpha(int c)
{
if ((c >= 97 && c <= 123) || (c >= 65 && c <= 91))
{
return (1);
}
else
{
return (0);
}
}
