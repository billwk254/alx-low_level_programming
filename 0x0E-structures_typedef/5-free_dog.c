#include <stdlib.h>
#include <stddef.h>
#include "dog.h"

/**
 * free_dog - dog struct memory freed
 * @d: pointer to the dog struct
 */
void free_dog(dog_t *d)
{
if (d == NULL)
return;

free(d->name);
free(d->owner);
free(d);
}
