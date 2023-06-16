#include <stdio.h>

/**
 * main - prints all single digit numbers
 * of base 10 starting from 0, followed by a new line
 *
 * Return: always 0 (Success)
 */
int main(void)
{
	char c;

	for (c = '1'; c <= '9'; c++)
		putchar(c);
	putchar('\n');
	return (0);
}
