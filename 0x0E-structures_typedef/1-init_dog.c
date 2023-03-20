/**
 * init_dog - initializes a dog structure
 * @d: pointer to the dog structure
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Description: This function initializes a dog
 * structure with the given values.
 * If the pointer to the dog structure is NULL,
 * the function does nothing.
 */
#include "dog.h"
#include <stddef.h>
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		return;

	d->name = name;
	d->age = age;
	d->owner = owner;
}
