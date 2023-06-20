#include "main.h"

/**
 * _islower - checks for alphabetic character
 *
 * @c: character to ckeck
 *
 * Return: 1 if c is lowercase, 0 otherwise
 */
int _isalpha(int c)
{
	return (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')));
}
