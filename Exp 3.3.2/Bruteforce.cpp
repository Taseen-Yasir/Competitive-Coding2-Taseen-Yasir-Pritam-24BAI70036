#include <iostream>
#include <vector>
using namespace std;

void dfs(int r, int c,
         vector<vector<char>>& grid,
         vector<vector<bool>>& visited)
{
    int m = grid.size();
    int n = grid[0].size();

    if (r < 0 || r >= m || c < 0 || c >= n)
        return;

    if (visited[r][c] || grid[r][c] == '0')
        return;

    visited[r][c] = true;

    dfs(r - 1, c, grid, visited); 
    dfs(r + 1, c, grid, visited); 
    dfs(r, c - 1, grid, visited);
    dfs(r, c + 1, grid, visited); 
}

int numIslands(vector<vector<char>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> visited(
        m, vector<bool>(n, false)
    );

    int count = 0;

    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (grid[r][c] == '1' && !visited[r][c])
            {
            
                count++;

                dfs(r, c, grid, visited);
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
