#include <stdio.h>
#include "lists.h"

/**
 * startup - Prints a message before main function is executed
 **/
void startup(void) __attribute__ ((constructor));

void startup(void)
{
printf("You're beat! and yet, you must allow,\n");
printf("I bore my house upon my back!\n");
}
