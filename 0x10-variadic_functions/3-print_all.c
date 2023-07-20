#include "variadic_functions.h"

/**
 * print_char - prints character
 *
 * @args: conatains character to print
 */
void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_int - prints integer
 *
 * @args: conatains an integer to print
 */
void print_int(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_float - prints float
 *
 * @args: conatains a float to print
 */
void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_string - prints string
 *
 * @args: conatains string to print
 */
void print_string(va_list args)
{
	char *str = va_arg(args, char*);

	printf("%s", str ? str : "(nil)");
}
/**
 * print_all - prints anything
 *
 * @format: a list of types of arguments passed to the function
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0;

	print_t types[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string},
		{0, NULL}
	};

	va_start(args, format);
	while (format && format[i])
	{
		int j = 0;

		while (types[j].flag)
		{
			if (format[i] == types[j].flag)
			{
				types[j].f(args);
				if (format[i + 1])
					printf(", ");
			}
			j++;
		}
		i++;
	}
	va_end(args);
	printf("\n");
}
