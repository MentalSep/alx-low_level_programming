#include "main.h"

/**
 * malloc_checked - allocate memory using malloc
 *
 * @b: size the memory block
 *
 * Return: pointer to the allocated memory, otherwise
 * exists with status of value 98
 */
void *malloc_checked(unsigned int b)
{
	void *p = malloc(b);

	if (!p)
		exit(98);

	return (p);
}
