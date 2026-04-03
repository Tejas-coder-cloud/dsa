/*
Cycle detection in undirected graph using BFS 
Time & Space complexity:O(V+E)
Here "V" represents the number of vertices and "E" represents the number of edges
*/
#include<bits/stdc++.h>
using namespace std;
bool isCyclic(int src,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj)
{
    unordered_map<int,int>parent;
    parent[src]=-1;
    visited[src]=1;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int first=q.front();
        q.pop();
        for(auto neighbour:adj[first])
        {
            if(visited[neighbour]==true && neighbour!=parent[first])
            {
                return true;
            }
            else if(!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour]=true;
                parent[neighbour]=first;
            }
        }
    }
    return false;
}
string cycle_detection(vector<vector<int>> edges,int n,int m)
{
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            bool ans=isCyclic(i,visited,adj);
            if(ans==1)
            {
                return "Yes";
            }
        }
    }
    return "No";
}
int main()
{
    int n = 4; // Number of vertices
    int m = 4; // Number of edges
    vector<vector<int>> edges = 
    {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 0}
    };
    cout << "Cycle detected: " << cycle_detection(edges, n, m) << endl;
    // Example 2: A linear graph (No cycle)
    int n2 = 3;
    int m2 = 2;
    vector<vector<int>> edges2 = {
        {0, 1},
        {1, 2}
    };
    cout << "Cycle detected: " << cycle_detection(edges2, n2, m2) << endl;
    return 0;
}