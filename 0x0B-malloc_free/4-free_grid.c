#include <stdlib.h>

/**
 * free_grid - frees a 2D grid
 * @grid: pointer to the 2D array
 * @height: the height of the grid
 */
void free_grid(int **grid, int height)
{
int i;

if (grid == NULL)
return;

for (i = 0; i < height; i++)
free(grid[i]);

free(grid);
}
