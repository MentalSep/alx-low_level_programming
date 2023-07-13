#include "main.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 *
 * @ptr: pointer to the memory previously allocated with a
 * call to malloc: malloc(old_size)
 * @old_size:  size, in bytes, of the allocated space for ptr
 * @new_size:  new size, in bytes of the new memory block
 *
 * Return: pointer to new memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	int i;
	char *new;

	if (new_size == old_size)
		return (ptr);

	if (!ptr)
	{
		new = malloc(new_size);
		if (!new)
			return (NULL);
		return (new);
	}

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	new = malloc(new_size);
	if (!new_size)
		return (NULL);

	for (i = 0; ((char *)ptr)[i]; i++)
		new[i] = ((char *)ptr)[i];
	free(ptr);

	return (new);
}
