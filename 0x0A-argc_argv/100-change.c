#include "main.h"

/**
 * main - prints the minimum number of coins to make change
 * for an amount of money
 *
 * @argc: argument count.
 * @argv: argument vector.
 *
 * Return: 0 (success), otherwise 1 (failure).
 */
int main(int argc, char *argv[])
{
	int cents, coins;

	if (argc != 2)
		return (printf("Error\n"), 1);

	cents = atoi(argv[1]);
	if (cents < 0)
		return (printf("0\n"), 1);

	for (coins = 0; cents; coins++)
	{
		if (cents - 25 >= 0)
			cents -= 25;
		else if (cents - 10 >= 0)
			cents -= 10;
		else if (cents - 5 >= 0)
			cents -= 5;
		else if (cents - 2 >= 0)
			cents -= 2;
		else if (cents - 1 >= 0)
			cents -= 1;
	}
	printf("%d\n", coins);
	return (0);
}
