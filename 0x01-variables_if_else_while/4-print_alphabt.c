#include <stdio.h>

/**
 * main - prints the alphabet in lowercase except
 * 'q' and 'e', followed by a new line
 *
 * Return: always 0 (Success)
 */
int main(void)
{
	char c;

	for (c = 'a'; c <= 'z'; c++)
	{
		if (c != 'q' && c != 'e')
			putchar(c);
	}
	putchar('\n');
	return (0);
}
