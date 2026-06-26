/*
Number of Provinces (DFS)
Time Complexity: O(V^2)
Space Complexity: O(V)
*/
#include <bits/stdc++.h>
using namespace std;
void dfs(int i, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[i] = true;
    for (int j = 0; j < adj[i].size(); j++)
    {
        if (adj[i][j] == 1 && !vis[j])
        {
            dfs(j, adj, vis);
        }
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    int numOfProvinces = 0;
    int n = isConnected.size();
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, isConnected, vis);
            numOfProvinces++;
        }
    }
    return numOfProvinces;
}
int main()
{
    int n;
    cout << "Enter number of cities: ";
    cin >> n;
    vector<vector<int>> isConnected(n, vector<int>(n));
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> isConnected[i][j];
        }
    }
    cout << "Number of Provinces: " << findCircleNum(isConnected) << endl;
    return 0;
}