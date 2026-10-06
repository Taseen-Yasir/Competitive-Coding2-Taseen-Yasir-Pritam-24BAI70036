#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>& grid,
         int r, int c,
         int m, int n)
{
    if (r < 0 || r >= m ||
        c < 0 || c >= n ||
        grid[r][c] != '1')
    {
        return;
    }

    grid[r][c] = '0';

    dfs(grid, r - 1, c, m, n); // Up
    dfs(grid, r + 1, c, m, n); // Down
    dfs(grid, r, c - 1, m, n); // Left
    dfs(grid, r, c + 1, m, n); // Right
}

int numIslands(vector<vector<char>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();

    int count = 0;

    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (grid[r][c] == '1')
            {
                
                count++;

            
                dfs(grid, r, c, m, n);
            }
        }
    }

    return count;
}

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    cout << "Number of Islands = "
         << numIslands(grid) << endl;

    return 0;
}