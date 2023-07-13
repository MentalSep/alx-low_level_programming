#include "main.h"

/**
 * str_concat - concatenates two strings
 *
 * @s1: first string.
 * @s2: secind string.
 *
 * Return: pointer to new string, otherwise NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	int i, j, len1, len2;
	char *new;

	s1 == NULL ? s1 = "" : s1;
	s2 == NULL ? s2 = "" : s2;

	for (len1 = 0; s1[len1]; len1++)
		;
	for (len2 = 0; s2[len2]; len2++)
		;

	new = malloc(sizeof(*new) * (len1 + len2 + 1));
	if (!new)
		return (NULL);

	for (i = 0; s1[i]; i++)
		new[i] = s1[i];
	for (j = 0; s2[j]; j++, i++)
		new[i] = s2[j];
	new[i] = '\0';

	return (new);
}
