/*
Orange rotting
N= No of Rows
M=No of Columns
Time complexity:O(M*N)
Space complexity:O(M*N)
 */
#include <bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<pair<int, int>, int>> q;
    int time = 0, ans = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
            }
        }
    }
    while (!q.empty())
    {
        int i = q.front().first.first;
        int j = q.front().first.second;
        int time = q.front().second;
        q.pop();
        ans = max(ans, time);
        if (i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] == 1)
        {
            q.push({{i - 1, j}, time + 1});
            visited[i - 1][j] = true;
        }
        if (j + 1 < m && !visited[i][j + 1] && grid[i][j + 1] == 1)
        {
            q.push({{i, j + 1}, time + 1});
            visited[i][j + 1] = true;
        }
        if (i + 1 < n && !visited[i + 1][j] && grid[i + 1][j] == 1)
        {
            q.push({{i + 1, j}, time + 1});
            visited[i + 1][j] = true;
        }
        if (j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] == 1)
        {
            q.push({{i, j - 1}, time + 1});
            visited[i][j - 1] = true;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && !visited[i][j])
            {
                return -1;
            }
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> grid1 = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}};
    int ans = orangesRotting(grid1);
    cout << "Minutes to rot all oranges (Grid 1): " << ans << endl;
    return 0;
}