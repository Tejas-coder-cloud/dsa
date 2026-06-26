/*
Floyd-Warshall Algorithm (All-Pairs Shortest Path)
V = Number of vertices
E = Number of edges
Time Complexity: O(V^3)
Space Complexity: O(V^2)
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
void floydWarshall(vector<vector<int>> &dist, int V)
{
    for (int via = 0; via < V; via++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][via] != INF && dist[via][j] != INF)
                {
                    dist[i][j] = min(dist[i][j],dist[i][via] + dist[via][j]);
                }
            }
        }
    }
}
int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    vector<vector<int>> dist(V, vector<int>(V, INF));
    for (int i = 0; i < V; i++)
        dist[i][i] = 0;
    cout << "Enter each edge (u v weight):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        dist[u][v] = wt;
        // Uncomment the next line for an undirected graph.
        // dist[v][u] = wt;
    }
    floydWarshall(dist, V);
    cout << "\nShortest Distance Matrix:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}