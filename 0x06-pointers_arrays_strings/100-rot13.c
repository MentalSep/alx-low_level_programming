#include "main.h"

/**
 * rot13 - encodes rot13 with a string.
 *
 * @str: string to encode
 *
 * Return: pointer to str.
 */
char *rot13(char *str)
{
	char *input, *output;
	int i, j;

	input = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	output = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	for (i = 0; str[i]; i++)
		for (j = 0; input[j]; j++)
			if (str[i] == input[j])
			{
				str[i] = output[j];
				break;
			}
	return (str);
}
