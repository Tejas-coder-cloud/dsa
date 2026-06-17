/*
Number of Islands
N= No of Rows
M=No of Columns
Time complexity:O(M*N)
Space complexity:O(M*N)
 */
#include <bits/stdc++.h>
using namespace std;
void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<char>> &grid, int n, int m)
{
    if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || grid[i][j] != '1')
    {
        return;
    }
    visited[i][j] = true;
    dfs(i - 1, j, visited, grid, n, m);
    dfs(i, j + 1, visited, grid, n, m);
    dfs(i, j - 1, visited, grid, n, m);
    dfs(i + 1, j, visited, grid, n, m);
}
int numIslands(vector<vector<char>> &grid)
{
    int islands = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1' && !visited[i][j])
            {
                dfs(i, j, visited, grid, n, m);
                islands++;
            }
        }
    }
    return islands;
}
int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    int result = numIslands(grid);
    cout << "The number of islands is: " << result << endl;

    return 0;
}