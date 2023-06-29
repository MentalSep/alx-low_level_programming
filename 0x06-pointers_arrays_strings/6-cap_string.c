#include "main.h"

/**
 * SeperatorCheck - checks for seperator
 *
 * @c: chacracter to check.
 *
 * Return: 1 if c is a seprator, 0 otherwise.
 */
int SeperatorCheck(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
			c == ',' || c == ';' || c == '.' ||
			c == '!' || c == '?' || c == '"' ||
			c == '(' || c == ')' || c == '{' ||
			c == '}');
}
/**
 * cap_string - capitalizes all words of a string .
 *
 * @str: string to be changed.
 *
 * Return: pointer to str.
 */
char *cap_string(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		if (i == 0 || SeperatorCheck(str[i - 1]))
			(str[i] >= 'a' && str[i] <= 'z') ? str[i] -= 32 : 0;
	return (str);
}
