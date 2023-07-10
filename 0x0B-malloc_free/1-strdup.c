#include "main.h"

/**
 * _strdup - eturns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 *
 * @str: pointer to string.
 *
 * Return:  returns a pointer to the duplicated string. It
 * returns NULL if insufficient memory was available
 */
char *_strdup(char *str)
{
	int i;
	char *dup;

	if (!str)
		return (NULL);
	for (i = 0; str[i]; i++)
		;
	dup = malloc(sizeof(*dup) * (i + 1));
	if (!dup)
		return (NULL);
	for (i = 0; str[i]; i++)
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}
