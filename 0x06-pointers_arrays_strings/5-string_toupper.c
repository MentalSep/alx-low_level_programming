#include "main.h"

/**
 * string_toupper - changes all lowercase letters if string to uppercase.
 *
 * @str: string to be changed.
 *
 * Return: pointer to str.
 */
char *string_toupper(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		(str[i] >= 'a' && str[i] <= 'z') ? str[i] -= 32 : 0;
	return (str);
}
