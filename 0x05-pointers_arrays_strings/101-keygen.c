#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define CHECKSUM 2772

/**
 * main - generates a valid key for the program 101-crackme
 *
 * Return: 0 always success
 */
int main(void)
{
	int total = 0;
	char c;

	srand(time(NULL));
	for (; total <= 2695;)
	{
		c = rand() % (126 - 48) + '0';
		total += c;
		printf("%c", c);
	}
	printf("%c", (CHECKSUM - total));
	return (0);
}
