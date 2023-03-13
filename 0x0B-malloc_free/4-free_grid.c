/**
 * free_grid - function that frees a 2 dimensional grid
 *  previously created by the alloc_grid function
 *  Return: Nothing
 *  @grid: pointer to a pointer
 *  @height: int parameter
 */

#include <stdlib.h>

void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL)
	{
		return;
	}
	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}

