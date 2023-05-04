#include "main.h"
#include <stdio.h>
/**
 * get_endianness - checks the endianness of the system
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
unsigned int i = 1;
char *c = (char *)&i;
return (*c ? 1 : 0);
}
