#include <stdio.h>
#include "dog.h"

/**
 * print_dog - prints the information of a dog
 * @d: pointer to the dog struct to print
 */
void print_dog(struct dog *d)
{
if (d == NULL)
return;

printf("Name: %s\n", d->name != NULL ? d->name : "(nil)");
printf("Age: %.6f\n", d->age);
printf("Owner: %s\n", d->owner != NULL ? d->owner : "(nil)");
}
