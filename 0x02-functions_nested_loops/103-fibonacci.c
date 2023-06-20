#include "main.h"

/**
 * main - write a program that finds and prints the sum of
 * the even-valued terms, followed by a new line.
 *
 * Return: alwyas 0
 */
int main(void)
{
	unsigned long cur = 1, prev = 0, sum = 0, next;

	for (; cur < 4000000;)
	{
		if (cur % 2 == 0)
			sum += cur;
		next = prev + cur;
		prev = cur;
		cur = next;
	}
	printf("%ld\n", sum);
	return (0);
}
