/*
Cheapest Flights Within K Stops (BFS)
V = Number of vertices (cities)
E = Number of edges (flights)
Time Complexity: O(V + E)
Space Complexity: O(V + E)
*/
#include <bits/stdc++.h>
using namespace std;
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
{
    vector<pair<int, int>> graph[n];
    // Build adjacency list
    for (int i = 0; i < flights.size(); i++)
    {
        int u = flights[i][0];
        int v = flights[i][1];
        int wt = flights[i][2];
        graph[u].push_back({v, wt});
    }
    queue<pair<int, pair<int, int>>> q;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    q.push({src, {0, -1}});
    while (!q.empty())
    {
        auto val = q.front();
        q.pop();
        int u = val.first;
        int cost = val.second.first;
        int stops = val.second.second;
        for (auto edge : graph[u])
        {
            int v = edge.first;
            int wt = edge.second;

            if (cost + wt < dist[v] && stops + 1 <= k)
            {
                dist[v] = cost + wt;
                q.push({v, {dist[v], stops + 1}});
            }
        }
    }
    if (dist[dst] == INT_MAX)
       return -1;
    return dist[dst];
}
int main()
{
    int n, m;
    cout << "Enter number of cities: ";
    cin >> n;
    cout << "Enter number of flights: ";
    cin >> m;
    vector<vector<int>> flights(m, vector<int>(3));
    cout << "Enter each flight as: source destination cost\n";
    for (int i = 0; i < m; i++)
    {
        cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
    }
    int src, dst, k;
    cout << "Enter source city: ";
    cin >> src;
    cout << "Enter destination city: ";
    cin >> dst;
    cout << "Enter maximum number of stops: ";
    cin >> k;
    int ans = findCheapestPrice(n, flights, src, dst, k);
    cout << "Cheapest Price: " << ans << endl;
    return 0;
}