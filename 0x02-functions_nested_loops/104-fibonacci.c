#include "main.h"

/**
 * main - prints the first 98 Fibonacci numbers,
 * starting with 1 and 2, followed by a new line.
 *
 * Return: always 0
 */

int main(void)
{
	unsigned long i, prev = 1, cur = 2, prev_pt1, prev_pt2, cur_pt1, cur_pt2;

	printf("%lu", prev);

	for (i = 1; i < 91; i++)
	{
		printf(", %lu", cur);
		cur = cur + prev;
		prev = cur - prev;
	}
	prev_pt1 = prev / 1000000000;
	prev_pt2 = prev % 1000000000;
	cur_pt1 = cur / 1000000000;
	cur_pt2 = cur % 1000000000;

	for (i = 92; i < 99; ++i)
	{
		printf(", %lu", cur_pt1);
		printf("%lu", cur_pt2);
		cur_pt1 = cur_pt1 + prev_pt1;
		prev_pt1 = cur_pt1 - prev_pt1;
		cur_pt2 = cur_pt2 + prev_pt2;
		prev_pt2 = cur_pt2 - prev_pt2;
	}
	printf("\n");
	return (0);
}
