#include "main.h"

/**
 * main - prints the first 98 Fibonacci numbers,
 * starting with 1 and 2, followed by a new line.
 *
 * Return: always 0
 */

int main(void)
{
	int i;
	unsigned long cur = 1, prev = 1, next;

	for (i = 0; i < 50; i++)
	{
		printf("%ld%s", cur, (i != 49) ? ", " : "\n");
		next = cur + prev;
		prev = cur;
		cur = next;
	}
	return (0);
}
