#include "main.h"

/**
 * _calloc - allocates memory for an array using malloc, and setting it to zero
 *
 * @nmemb: number of elements allocate memory for
 * @size: size of each elemnt
 *
 * Return: pointer to the allocated memory, other NULL if it fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int i;

	if (!nmemb || !size)
		return (NULL);

	p = malloc(nmemb * size);
	if (!p)
		return (NULL);

	for (i = 0; i < (nmemb * size); i++)
		p[i] = 0;

	return (p);
}
