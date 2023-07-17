#include "dog.h"

/**
 * free_dog - frees dogs
 *
 * @d: pointer to dtruct dog_t
 *
 * Return: void
 */
void free_dog(dog_t *d)
{
	if (d)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
