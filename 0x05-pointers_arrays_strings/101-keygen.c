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
	int sum = 0, n = 0, i = 0;
	char str[100];

	srand(time(NULL));
	while (sum < CHECKSUM)
	{
		if (CHECKSUM - sum < 48)
			sum -= str[--i];
		else if (CHECKSUM - sum <= 126)
			n = CHECKSUM - sum;
		else
			n = rand() % (126 - 48) + 48;
		if (n)
		{
			str[i++] = n;
			sum += n;
		}
		n = 0;
	}
	str[i] = '\0';
	printf("%s", str);
	return (0);
}
