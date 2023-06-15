#include <unistd.h>

/**
 * main - a program that prints a string without
 * using puts or printf
 *
 * Return: returns 1 (Failure)
 */
int main(void)
{
	char *str = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

	while (*str)
	{
		write(STDERR_FILENO, str, 1);
		str++;
	}
	return (1);
}
