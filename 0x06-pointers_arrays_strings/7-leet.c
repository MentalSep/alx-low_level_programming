#include "main.h"

/**
 * leet - encodes a string to 1337
 *
 * @str: string to encode.
 *
 * Return: pointer to str.
 */
char *leet(char *str)
{
	int i, j;
	char *upper = "LETOA";
	char *lower = "letoa";
	char *encode = "13704";

	for (i = 0; str[i]; i++)
		for (j = 0; upper[j] && lower[j]; j++)
			if (str[i] == upper[j] || str[i] == lower[j])
				str[i] = encode[j];
	return (str);
}
