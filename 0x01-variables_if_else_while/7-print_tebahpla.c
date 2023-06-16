#include <stdio.h>

/**
 * main - prints the alphabet in lowercase in reverse, followed by a new line
 *
 * Return: always 0 (Success)
 */
int main(void)
{
	char c;

	for (c = 'z'; c >= 'a'; c--)
		putchar(c);
	putchar('\n');
	return (0);
}
