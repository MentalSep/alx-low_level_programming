#include "main.h"

/**
 * _strcat - concatenates two strings.
 *
 * @dest: destination string.
 * @src: source string.
 *
 * Return: pointer to dest.
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j;

	while (dest[i])
		i++;
	for (j = 0; src[j]; i++, j++)
		dest[i] = src[j];
	dest[i] = '\0';
	return (dest);
}
