#include <unistd.h>

/**
 * main - Write "_putchar" followed by a newline
 *
 * Return: always 0
 */
int main(void)
{
	write(STDOUT_FILENO, "_putchar\n", 9);
	return (0);
}
