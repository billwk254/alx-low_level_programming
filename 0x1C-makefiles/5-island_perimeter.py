#!/usr/bin/python3
"""
Module to calculate the perimeter of an island in a grid.
"""


def island_perimeter(grid):
    """
    Function to calculate the perimeter of an island in a grid.

    Args:
        grid (list[list[int]]): A list of lists containing 0s and 1s, where
            0 represents water and 1 represents land.

    Returns:
        int: The perimeter of the island.

    """
    perimeter = 0
    rows, cols = len(grid), len(grid[0])

    for row in range(rows):
        for col in range(cols):
            if grid[row][col] == 1:
                perimeter += 4

                if row > 0 and grid[row - 1][col] == 1:
                    perimeter -= 2

                if col > 0 and grid[row][col - 1] == 1:
                    perimeter -= 2

    return perimeter

