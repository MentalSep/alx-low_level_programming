#include "main.h"

/**
 * string_nconcat - concatenates two strings
 *
 * @s1: first string.
 * @s2: second string.
 * @n: number of bytes to concatenate from s2
 *
 * Return: pointer to new string, otherwise NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i, j, len1, len2;
	char *new;

	s1 == NULL ? s1 = "" : s1;
	s2 == NULL ? s2 = "" : s2;

	for (len1 = 0; s1[len1]; len1++)
		;
	for (len2 = 0; s1[len2]; len2++)
		;

	n >= len2 ? n = len2 : n;
	new = malloc(sizeof(*new) * (len1 + n + 2));
	if (!new)
		return (NULL);

	for (i = 0; s1[i]; i++)
		new[i] = s1[i];
	for (j = 0; j <= n; j++, i++)
		new[i] = s2[j];
	new[i] = '\0';

	return (new);
}
