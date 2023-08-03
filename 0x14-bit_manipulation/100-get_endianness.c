#include "main.h"

/**
 * get_endianness - checks the endianness
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	int test_var = 1;
	unsigned char *endian_check = (unsigned char *)&test_var;

	return (*endian_check);
}
