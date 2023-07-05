#include "main.h"

/**
 * wildcmp - compares two strings while ignoring the special character *
 *
 * @s1: first string.
 * @s2: second string.
 *
 * Return: 1 if the strings can be considered identical, otherwise return 0
 */
int wildcmp(char *s1, char *s2)
{
	if (!*s1 && !*s2)
		return (1);
	else if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	else if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2)));
	return (0);
}
