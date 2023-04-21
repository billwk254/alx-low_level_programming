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
va_list args;
unsigned int i = 0, j;
char *str;

const char *type_list = "cifs";
char *sep = "";
va_start(args, format);

while (format && format[i])
{
j = 0;
while (type_list[j])
{
if (type_list[j] == format[i])
{
printf("%s", sep);
switch (type_list[j])
{
case 'c':
printf("%c", va_arg(args, int));
break;
case 'i':
printf("%d", va_arg(args, int));
break;
case 'f':
printf("%f", va_arg(args, double));
break;
case 's':
str = va_arg(args, char *);
if (str == NULL)
printf("(nil)");
else
printf("%s", str);
break;
default:
break;
}
sep = ", ";
}
j++;
}
i++;
}

va_end(args);
printf("\n");
}
