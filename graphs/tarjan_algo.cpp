/*
Articulation Points (Tarjan's Algorithm)
V = Number of vertices
E = Number of edges
Time Complexity: O(V + E)
Space Complexity: O(V + E)
*/
#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    vector<vector<int>> adj;
    int V;
    int timer;
    vector<int> dt, low;
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int u, int parU, set<int> &criticalPoints)
    {
        dt[u] = low[u] = ++timer;
        int children = 0;
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if (dt[v] == -1)
            {
                children++;
                dfs(v, u, criticalPoints);
                // Update low value
                low[u] = min(low[u], low[v]);
                // Articulation Point (Non-root)
                if (parU != -1 && low[v] >= dt[u])
                {
                    criticalPoints.insert(u);
                }
            }
            else if (v != parU)
            {
                low[u] = min(low[u], dt[v]);
            }
        }
        if (parU == -1 && children > 1)
        {
            criticalPoints.insert(u);
        }
    }
    int articulationPoints()
    {
        timer = 0;
        dt.assign(V, -1);
        low.assign(V, -1);
        set<int> criticalPoints;
        for (int i = 0; i < V; i++)
        {
            if (dt[i] == -1)
            {
                dfs(i, -1, criticalPoints);
            }
        }
        return criticalPoints.size();
    }
};

int main()
{
    Graph graph(6);
    graph.addEdge(1, 0);
    graph.addEdge(1, 2);
    graph.addEdge(4, 3);
    graph.addEdge(4, 5);
    graph.addEdge(4, 1);
    cout << "Number of Articulation Points: "<< graph.articulationPoints() << endl;
    return 0;
}