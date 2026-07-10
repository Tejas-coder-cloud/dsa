/*
Rat in a maze
Time complexity:O(4^n*n)
Space complexity:O(n^n)
*/
#include <bits/stdc++.h>
using namespace std;
void helper(vector<vector<int>> &maze, int row, int col, string path, vector<string> &ans, vector<vector<bool>> &visited)
{
    int n = maze.size();
    if (row < 0 || col < 0 || row >= n || col >= n || maze[row][col] == 0 || visited[row][col])
    {
        return;
    }
    if (row == maze.size() - 1 && col == maze[0].size() - 1)
    {
        ans.push_back(path);
        return;
    }
    visited[row][col] = true;
    helper(maze, row + 1, col, path + "D", ans, visited);
    helper(maze, row, col - 1, path + "L", ans, visited);
    helper(maze, row, col + 1, path + "R", ans, visited);
    helper(maze, row - 1, col, path + "U", ans, visited);
    visited[row][col] = false;
}
vector<string> ratInMaze(vector<vector<int>> &maze)
{
    int n = maze.size();
    if (n==0|| maze[0][0] == 0|| maze[n-1][n-1]==0)
    {
        return {};
    }
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string path = "";
    vector<string> ans;
    helper(maze, 0, 0, path, ans, visited);
    
    return ans;
}
int main()
{
    vector<vector<int>> maze=
    {
        {1,0,0,0},
        {1,1,0,0},
        {1,1,0,0},
        {0,1,1,1}
    };
    vector<string> ans=ratInMaze(maze);
    cout<<"All the possible path are: "<<endl;
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}
/*
Space optimized versiom
Rat in a maze
Time complexity:O(4^n*n)
Space complexity:O(n*n)
*/
/*
#include <bits/stdc++.h>
using namespace std;
void helper(vector<vector<int>> &maze, int row, int col, string path, vector<string> &ans)
{
    int n = maze.size();
    if (row < 0 || col < 0 || row >= n || col >= n || maze[row][col] == 0 || maze[row][col]==-1)
    {
        return;
    }
    if (row == maze.size() - 1 && col == maze[0].size() - 1)
    {
        ans.push_back(path);
        return;
    }
    maze[row][col] = -1;
    helper(maze, row + 1, col, path + "D", ans);
    helper(maze, row, col - 1, path + "L", ans);
    helper(maze, row, col + 1, path + "R", ans);
    helper(maze, row - 1, col, path + "U", ans);
    maze[row][col] = 1;
}
vector<string> ratInMaze(vector<vector<int>> &maze)
{
    int n = maze.size();
    string path = "";
    vector<string> ans;
    helper(maze, 0, 0, path, ans);
    if (maze[0][0] == 0)
    {
        return {};
    }
    return ans;
}
int main()
{
    vector<vector<int>> maze=
    {
        {1,0,0,0},
        {1,1,0,0},
        {1,1,0,0},
        {0,1,1,1}
    };
    vector<string> ans=ratInMaze(maze);
    cout<<"All the possible path are: "<<endl;
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}
*/