#include "main.h"

/**
 * main - multiplies two numbers.
 *
 * @argc: argument count.
 * @argv: argument vector.
 *
 * Return: 0 (success), otherwise 1 (failure).
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		return (printf("Error\n"), 1);
	printf("%d\n", atoi(argv[1]) * atoi(argv[2]));
	return (0);
}
