#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * f3 - helper function
 * @a0: username
 * @a1: username lentgh
 * @type: type of function
 * Return: the calculated value
 */
int f3(char *a0, unsigned int a1, int type)
{
	unsigned int v0;
	unsigned int v1;

	/* ------------ f3 ---------------*/
	if (type == 3)
	{
		v0 = 1;
		for (v1 = 0; v1 < a1; v1 += 1)
		{
			v0 *= a0[v1];
		}
		return ((v0 ^ 85) & 63);
	}
	/* ------------ f2 ---------------*/
	else
	{
		v0 = 0;
		for (v1 = 0; v1 < a1; v1 += 1)
		{
			v0 += a0[v1];
		}
		return ((v0 ^ 79) & 63);
	}
}

/**
 * f4 - helper function
 * @a0: username
 * @a1: username lentgh
 * Return: the calculated value
 */
int f4(char *a0, unsigned int a1)
{
	unsigned int v0;
	unsigned int v1;

	v0 = *(a0);
	for (v1 = 0; v1 < a1; v1 += 1)
	{
		if (a0[v1] > (char)v0)
			v0 = a0[v1];
	}
	srand(v0 ^ 14);
	return (rand() & 63);
}

/**
 * f5 - helper function
 * @a0: username
 * @a1: username lentgh
 * Return: the calculated value
 */
int f5(char *a0, unsigned int a1)
{
	unsigned int v0;
	unsigned int v1;
	unsigned int v3;
	unsigned int v4;

	v0 = 0;
	for (v1 = 0; v1 < a1; v1 += 1)
	{
		v0 += a0[v1] * a0[v1];
	}
	v3 = v0;
	*((char *)&v3) = (char)v0 ^ 239;
	v4 = v3 & 63;
	return (v4);
}

/**
 * f6 - helper function
 * @a0: unsigned int
 * Return: the calculated value
 */
int f6(unsigned int a0)
{
	unsigned int v0;
	unsigned int v1;
	unsigned int v3;
	unsigned int v4;

	v0 = 0;
	for (v1 = 0; a0 > v1; v1 += 1)
	{
		v0 = rand();
	}
	v3 = v0;
	*((char *)&v3) = (char)v0 ^ 229;
	v4 = v3 & 63;
	return (v4);
}

/**
 * main - keygen for crackme5
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0, 1 if arguments aren't met
 */
int main(int argc, char *argv[])
{
	long numbers[] = {0x3877445248432d41, 0x42394530534e6c37,
					  0x4d6e706762695432, 0x74767a5835737956,
					  0x2b554c59634a474f, 0x71786636576a6d34,
					  0x723161513346655a, 0x6b756f494b646850};
	unsigned int len;
	char *string = (char *) numbers, *username = argv[1], password[7];

	if (argc != 2)
		return (1);
	/*for future ref this is from decompiler 'angr' dogbolt*/
	len = strlen(username);
	password[0] = string[(len ^ 59) & 63]; /* f1 */
	password[1] = string[f3(username, len, 2)];
	password[2] = string[f3(username, len, 3)];
	password[3] = string[f4(username, len)];
	password[4] = string[f5(username, len)];
	password[5] = string[f6(username[0])];
	password[6] = '\0';
	printf("%s", password);

	return (0);
}
