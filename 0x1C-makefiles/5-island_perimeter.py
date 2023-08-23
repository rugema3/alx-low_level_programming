#!/usr/bin/python3
"""5-island_perimeter module."""

def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in grid using recursion.

    Args:
        grid (list of list of integers): The grid representing the island.

    Returns:
        int: The perimeter of the island.
    """
    rows = len(grid)
    cols = len(grid[0])

    def dfs(row, col):
        """
        Recursive depth-first search to calculate the perimeter.

        Args:
            row (int): Current row index.
            col (int): Current column index.

        Returns:
            int: The contribution to the perimeter from the current cell.
        """
        # Base case: Check if current cell is out of bounds or water
        if row < 0 or row >= rows or col < 0 or col >= cols:
            return 1  # Count boundary as water

        if grid[row][col] == 0:
            return 1  # Count land adjacent to water

        if grid[row][col] == -1:
            return 0  # Already visited cell

        grid[row][col] = -1  # Mark cell as visited

        perimeter = 0
        perimeter += dfs(row + 1, col)  # Down
        perimeter += dfs(row - 1, col)  # Up
        perimeter += dfs(row, col + 1)  # Right
        perimeter += dfs(row, col - 1)  # Left

        return perimeter

    # Find the first land cell to start recursion
    for row in range(rows):
        for col in range(cols):
            if grid[row][col] == 1:
                return dfs(row, col)

    return 0
