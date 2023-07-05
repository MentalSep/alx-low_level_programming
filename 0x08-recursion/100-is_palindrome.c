#include "main.h"

/**
 * _strlen_recursion - returns the length of a string.
 *
 * @s: string to count the length of.
 *
 * Return: the lentgh the s.
 */
int _strlen_recursion(char *s)
{
	if (!*s)
		return (0);
	return (1 + _strlen_recursion(s + 1));
}

/**
 * _check - checks if a string is a palindrome
 *
 * @s: string to check
 * @i: integer
 * @length: length of string
 *
 * Return: 1 if s is a plaindrome, 0 otherwise.
 */
int _check(char *s, int i, int length)
{
	if (i >= length)
		return (1);
	else if (s[i] == s[length])
		return (_check(s, i + 1, length - 1));
	return (0);
}

/**
 * is_palindrome - checks if a string is a palindrome
 *
 * @s: string to check
 *
 * Return: 1 if s is a plaindrome, 0 otherwise.
 */
int is_palindrome(char *s)
{
	int i = 0, length = _strlen_recursion(s);

	if (!*s)
		return (1);
	return (_check(s, i, length - 1));
}
