#!/usr/bin/python3
"""
function def island_perimeter(grid): that returns 
the perimeter of the island described in grid
"""


def island_perimeter(grid):
    """
    Calculate the perimeter of the island.

    Args:
        grid : The grid representing the island.

    Returns:
        int: perimeter of the island.
    """
    width = len(grid[0])
    height = len(grid)
    edges_num = 0
    island_size = 0

    for i in range(height):
        for j in range(width):
            if grid[i][j] == 1:
                island_size += 1
                if (j > 0 and grid[i][j - 1] == 1):
                    edges_num += 1
                if (i > 0 and grid[i - 1][j] == 1):
                    edges_num += 1
    return island_size * 4 - edges_num * 2
