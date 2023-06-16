#include <stdio.h>

/**
 * main - prints all single digit numbers
 * of base 10 starting from 0 without
 * using type 'char', followed by a new line
 *
 * Return: always 0 (Success)
 */
int main(void)
{
	int c;

	for (c = 48; c <= 57; c++)
		putchar(c);
	putchar('\n');
	return (0);
}
