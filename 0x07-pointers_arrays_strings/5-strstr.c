#include "main.h"

/**
 * _strstr - locates a substring.
 *
 * @haystack: string to check.
 * @needle: string to look for.
 *
 * Return: pointer to the beginning of the loc	ted substring, or NULL
 * if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	for (i = 0; haystack[i]; i++)
	{
		for (j = 0; needle[j] && haystack[j + i];)
		{
			if (haystack[j + i] == needle[j])
				j++;
			else
				break;
		}
		if (!needle[j])
			return (&haystack[i]);
	}
	return (NULL);
}
