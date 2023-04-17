#include <stddef.h>
#include "dog.h"
/**
 * init_dog - initializes a dog struct
 * @d: pointer to the dog struct
 * @name: name of the dog (string)
 * @age: age of the dog (float)
 * @owner: name of the dog's owner (string)
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
if (d == NULL)
return;

d->name = name;
d->age = age;
d->owner = owner;
}
