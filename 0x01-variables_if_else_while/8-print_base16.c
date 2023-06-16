#include <stdio.h>

/**
 * main - a program that prints all the numbers of base
 * 16 in lowercase, followed by a newline.
 *
 * Return: always 0 (Success)
 */
int main(void)
{
	int n;

	for (n = 48; n < 103; n++)
	{
		putchar(n);
		if (n == 57)
			n = 96;
	}
	putchar('\n');
	return (0);
}
