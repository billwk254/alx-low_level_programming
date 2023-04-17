#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "dog.h"

/**
 * new_dog - creates a new dog struct
 * @name: name of the dog (string)
 * @age: age of the dog (float)
 * @owner: name of the dog's owner (string)
 *
 * Return: pointer to the new dog struct, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *dog;
char *name_copy, *owner_copy;
int name_len, owner_len;

dog = malloc(sizeof(dog_t));
if (dog == NULL)
return (NULL);

name_len = strlen(name);
name_copy = malloc(name_len + 1);
if (name_copy == NULL)
{
free(dog);
return (NULL);
}
strcpy(name_copy, name);

owner_len = strlen(owner);
owner_copy = malloc(owner_len + 1);
if (owner_copy == NULL)
{
free(name_copy);
free(dog);
return (NULL);
}
strcpy(owner_copy, owner);

dog->name = name_copy;
dog->age = age;
dog->owner = owner_copy;

return (dog);
}
