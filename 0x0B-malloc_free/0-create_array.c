#include "main.h"

/**
 * create_array - creates an array of chars, and initialize
 * it with a specific char.
 *
 * @size: size of the array.
 * @c: charater to initialize the array with.
 *
 * Return: pointer to the array, or NULL if it fails.
 */
char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *str = malloc(sizeof(c) * size);

	if (!str)
		return (NULL);
	for (i = 0; i < size; i++)
		str[i] = c;
	str[i] = '\0';
	return (str);
}
