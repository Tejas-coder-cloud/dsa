/*
Critical Connections in a Network (Tarjan's Algorithm)
V = Number of vertices
E = Number of edges
Time Complexity: O(V + E)
Space Complexity: O(V + E)
*/
#include <bits/stdc++.h>
using namespace std;
int timer;
vector<int> dt, low;
void dfs(int u, int parU,vector<vector<int>> &adj,vector<vector<int>> &bridges)
{
    dt[u] = low[u] = ++timer;
    for (int v : adj[u])
    {
        if (v == parU)
            continue;
        if (dt[v] == -1)
        {
            dfs(v, u, adj, bridges);
            // Update low value
            low[u] = min(low[u], low[v]);
            // Check if (u, v) is a bridge
            if (low[v] > dt[u])
            {
                bridges.push_back({u, v});
            }
        }
        else
        {
            // Back edge
            low[u] = min(low[u], dt[v]);
        }
    }
}
vector<vector<int>> criticalConnections(int n,vector<vector<int>> &connections)
{
    vector<vector<int>> adj(n);
    // Build adjacency list
    for (int i = 0; i < connections.size(); i++)
    {
        int u = connections[i][0];
        int v = connections[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    timer = 0;
    dt.assign(n, -1);
    low.assign(n, -1);
    vector<vector<int>> bridges;
    for (int i = 0; i < n; i++)
    {
        if (dt[i] == -1)
        {
            dfs(i, -1, adj, bridges);
        }
    }
    return bridges;
}
int main()
{
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    vector<vector<int>> connections;
    cout << "Enter each edge (u v):\n";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        connections.push_back({u, v});
    }
    vector<vector<int>> bridges = criticalConnections(n, connections);
    cout << "\nCritical Connections (Bridges):\n";
    if (bridges.empty())
    {
        cout << "No bridges found.\n";
    }
    else
    {
        for (auto &bridge : bridges)
        {
            cout << bridge[0] << " " << bridge[1] << endl;
        }
    }
    return 0;
}