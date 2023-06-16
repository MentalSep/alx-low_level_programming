#include <stdio.h>

/**
 * main - a program that prints all possible
 * different combinations of two-two digit numbers.
 *
 * Return: always 0 (Success)
 */
int main(void)
{
	int  n, m;

	for (n = 0; n < 100; n++)
	{
		for (m = n + 1; m < 100; m++)
		{
			putchar((n / 10) + '0');
			putchar((n % 10) + '0');
			putchar (' ');
			putchar((m / 10) + '0');
			putchar((m % 10) + '0');
			if (n != 98)
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar ('\n');
	return (0);
}
