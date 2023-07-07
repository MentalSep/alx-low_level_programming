#include "main.h"

/**
 * _atoi - converts a string to an integer
 *
 * @s: pointer to string
 *
 * Return: the converted value
 */
int _atoi(char *s)
{
	unsigned int n = 0;
	int sign = 1;

	while (*s)
	{
		if (*s == '-')
			sign *= -1;
		else if (*s >= '0' && *s <= '9')
		{
			while (*s >= '0' && *s <= '9')
			{
				n = (n * 10) + (*s - '0');
				s++;
			}
			break;
		}
		s++;
	}
	return (n * sign);
}
