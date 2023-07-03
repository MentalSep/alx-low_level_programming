#include "main.h"

/**
 * CheckForMatch - check for matching characters.
 *
 * @c: character to check.
 * @str: string of charcters to match.
 *
 * Return: 1 if c is a matching character, 0 otherwise.
 */
int CheckForMatch(char c, char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		if (str[i] == c)
			return (1);
	return (0);
}
/**
 * _strpbrk - searches a string for any of a set bytes.
 *
 * @s: string to check.
 * @accept: 
 */
char *_strpbrk(char *s, char *accept)
{
	unsigned int i = 0;

	while (s[i])
		if (CheckForMatch(s[i++], accept))
			return (&s[--i]);
	return (NULL);
}
