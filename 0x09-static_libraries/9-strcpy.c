#include "main.h"

/**
 * _strcpy - copies the string pointed by src, to the buffer pointed by dest
 *
 * @src: the source of the copy
 * @dest: the destination of the copy
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
