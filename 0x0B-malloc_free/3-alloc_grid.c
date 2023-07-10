#include "main.h"

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 *
 * @width: width of the grid
 * @height: height of the grid
 *
 * Return: pointer to the grid on succes, NULL on failure
 */
int **alloc_grid(int width, int height)
{
	int **grid, i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = calloc(height, sizeof(*grid));
	if (!grid)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		grid[i] = calloc(width, sizeof(**grid));
		if (!grid[i])
		{
			for (j = 0; j < 0; j++)
				free(grid[j]);
			return (NULL);
		}
	}
	return (grid);
}
