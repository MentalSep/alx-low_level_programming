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
 * _strspn - gets the length of prefix substring.
 *
 * @s: string to check.
 * @accept: Charatcters to match.
 *
 * Return: the number of characters in the initial segment of s
 * which consist only of characters from accept.
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i = 0;

	while (s[i])
	{
		if (CheckForMatch(s[i], accept))
			i++;
		else
			return (i);
	}
	return (i);
}
