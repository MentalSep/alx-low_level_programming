#include "main.h"

/**
 * _strchr - locates a character in a string.
 *
 * @s: string to check.
 * @c: character to locate.
 *
 * Return: pointer to s, otherwise NULL if character is not found.
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i]; i++)
		if (s[i] == c)
			return (&s[i]);
	/* in case c is '\0'*/
	if (s[i] == c)
		return (&s[i]);
	return (0);
}
