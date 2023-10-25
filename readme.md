# Maximum Moves in a Grid

This C++ code calculates the maximum number of moves that can be performed in a grid. You can start at any cell in the first column of the matrix and traverse the grid in a way that allows movement to cells with values strictly greater than the current cell's value.

## Code Explanation

```cpp
#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the maximum moves in a grid
int maxMoves(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    // Initialize a 2D DP array to store the maximum moves from each cell
    vector<vector<int> > dp(m, vector<int>(n, 0));

    // Initialize DP array with 1 for the first column
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }

    // Iterate through the grid to update the DP array
    for (int col = 1; col < n; col++) {
        for (int row = 0; row < m; row++) {
            for (int dRow : {-1, 0, 1}) {
                int newRow = row + dRow;
                if (newRow >= 0 && newRow < m && grid[newRow][col - 1] < grid[row][col]) {
                    dp[row][col] = max(dp[row][col], dp[newRow][col - 1] + 1);
                }
            }
        }
    }

    // Find the maximum moves in the last column
    int maxMoves = 0;
    for (int i = 0; i < m; i++) {
        maxMoves = max(maxMoves, dp[i][n - 1]);
    }

    return maxMoves;
}

int main() {
    vector<vector<int>> grid1 = {{2, 4, 3, 5}, {5, 4, 9, 3}, {3, 4, 2, 11}, {10, 9, 13, 15}};
    vector<vector<int>> grid2 = {{3, 2, 4}, {2, 1, 9}, {1, 1, 7}};

    // Calculate and print the maximum moves for the given grids
    cout << "Maximum moves for grid1: " << maxMoves(grid1) << endl; // Output: 3
    cout << "Maximum moves for grid2: " << maxMoves(grid2) << endl; // Output: 0

    return 0;
}
