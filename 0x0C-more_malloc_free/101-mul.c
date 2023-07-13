#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _isdigit - check if string is composed of digits
 *
 * @s: pointer to string
 *
 * Return: 0 if s is composed only of digits, otherwise 0
 */
int _isdigit(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		if (s[i] < '0' || s[i] > '9')
			return (1);
	return (0);
}
/**
 * print_arr - prints an array
 *
 * @result: array to print
 * @len: length of array
 *
 * Return: 0
 */
void print_arr(int *result, int len)
{
	int i;

	for (i = 0; i < len && result[i] == 0; i++)
		;

	if (i == len)
		printf("0");

	for (; i < len; i++)
		printf("%d", result[i]);

	printf("\n");
}

/**
 * main - multiplies two positive numbers
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int *result, i, j, len1, len2, tmp, sum;

	if (argc != 3 || _isdigit(argv[1]) || _isdigit(argv[2]))
	{
		printf("Error\n");
		exit(98);
	}

	len1 = strlen(argv[1]);
	len2 = strlen(argv[2]);

	result = calloc(len1 + len2, sizeof(int));
	if (!result)
		return (0);

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			tmp = (argv[1][i] - '0') * (argv[2][j] - '0');
			sum = result[i + j + 1] + tmp;
			result[i + j] += sum / 10;
			result[i + j + 1] = sum % 10;
		}
	}
	print_arr(result, len1 + len2);
	free(result);

	return (0);
}
