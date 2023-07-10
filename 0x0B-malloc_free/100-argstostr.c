#include "main.h"

/**
 * argstostr - concatenates all the arguments of the program
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: pointer to the new string, NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	char *new;
	int i, j, k, len;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0, len = 0; av[i]; i++)
	{
		for (j = 0; av[i][j]; j++)
			len++;
		len++;
	}

	new = malloc(sizeof(*new) * (len + 1));
	if (!new)
		return (NULL);

	for (i = 0, k = 0; av[i]; i++)
	{
		for (j = 0; av[i][j]; j++, k++)
			new[k] = av[i][j];
		new[k] = '\n';
		k++;
	}
	new[k] = '\0';

	return (new);
}
