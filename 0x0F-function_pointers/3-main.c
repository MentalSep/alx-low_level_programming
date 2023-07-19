#include "3-calc.h"

/**
 * main - performs simple operations
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: result of the operation
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;
	int (*op_function)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);

	op_function = get_op_func(argv[2]);
	if (!op_function)
	{
		printf("Error\n");
		exit(99);
	}

	result = op_function(num1, num2);
	printf("%d\n", result);

	return (0);
}
