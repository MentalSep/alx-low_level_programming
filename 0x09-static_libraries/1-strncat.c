#include "main.h"

/**
 * _strncat - concatenates two strings.
 *
 * @dest: destination string.
 * @src: source string.
 * @n: number of bytes to concatenate.
 *
 * Return: pointer to dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j;

	while (dest[i])
		i++;
	for (j = 0; src[j] && j < n; i++, j++)
		dest[i] = src[j];
	dest[i] = '\0';
	return (dest);
}
