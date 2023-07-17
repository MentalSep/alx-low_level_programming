#include "dog.h"
#include <stdlib.h>
#include <string.h>

/**
 * new_dog - creates a new dog
 *
 * @name: dog name
 * @age: dog age
 * @owner: dog's owner
 *
 * Return: pointer to struct dog_t, NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;

	if (!name || !age || !owner)
		return (NULL);

	dog = malloc(sizeof(dog_t));
	if (!dog)
		return (NULL);

	dog->age = age;

	dog->name = malloc((strlen(name) + 1));
	if (!dog->name)
	{
		free(dog);
		return (NULL);
	}
	dog->name = strcpy(dog->name, name);

	dog->owner = malloc((strlen(owner) + 1));
	if (!dog->owner)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}
	dog->owner = strcpy(dog->owner, owner);

	return (dog);
}
