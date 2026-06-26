/*
Strongly Connected Components (Kosaraju's Algorithm)
V = Number of vertices
E = Number of edges
Time Complexity: O(V + E)
Space Complexity: O(V + E)
*/
#include <bits/stdc++.h>
using namespace std;
void dfs1(int u, vector<vector<int>> &adj,vector<bool> &vis, stack<int> &st)
{
    vis[u] = true;
    for (int v : adj[u])
    {
        if (!vis[v])
            dfs1(v, adj, vis, st);
    }
    st.push(u);
}
void dfs2(int u, vector<vector<int>> &revGraph,
          vector<bool> &vis)
{
    vis[u] = true;
    cout << u << " ";
    for (int v : revGraph[u])
    {
        if (!vis[v])
            dfs2(v, revGraph, vis);
    }
}
int kosaraju(int V, vector<vector<int>> &adj)
{
    stack<int> st;
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs1(i, adj, vis, st);
    }
    vector<vector<int>> revGraph(V);
    for (int u = 0; u < V; u++)
    {
        for (int v : adj[u])
        {
            revGraph[v].push_back(u);
        }
    }
    fill(vis.begin(), vis.end(), false);
    int sccCount = 0;
    cout << "\nStrongly Connected Components:\n";
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            dfs2(node, revGraph, vis);
            cout << endl;
            sccCount++;
        }
    }
    return sccCount;
}
int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    vector<vector<int>> adj(V);
    cout << "Enter each directed edge (u v):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int scc = kosaraju(V, adj);
    cout << "\nNumber of Strongly Connected Components: "<< scc << endl;
    return 0;
}