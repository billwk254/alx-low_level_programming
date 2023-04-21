#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 *          c: char
 *          i: integer
 *          f: float
 *          s: char * (if the string is NULL, print (nil) instead)
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
va_list pa;
char *string;
int i;

i = 0;
va_start(pa, format);
while (format != NULL && format[i] != '\0')
{
switch (format[i])
{
case 'i':
printf("%i", va_arg(pa, int));
break;

case 'f':
printf("%f", va_arg(pa, double));
break;

case 'c':
printf("%c", (char) va_arg(pa, int));
break;

case 's':
string = va_arg(pa, char *);
if (string == NULL)
{
printf("(nil)");
break;
}
printf("%s", string);
break;
}

if ((format[i] == 'c' || format[i] == 'i' || format[i] == 'f' ||
format[i] == 's') && format[(i + 1)] != '\0')
printf(", ");
i++;
}
printf("\n");
va_end(pa);
}
