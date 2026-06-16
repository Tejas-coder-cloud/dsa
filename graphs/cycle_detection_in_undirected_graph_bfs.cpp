/*
Cycle detection in undirected graph using bfs 
V= No of Vertices
E=No of Edges
Time complexity:O(V+E)
Space complexity:O(V+E)
 */
#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int v;
    list<int> *l;
public:
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }
    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    bool isCycleDetectBFS(int src,vector<bool> & visited)
    {
        queue<pair<int,int>> q;
        q.push({src,-1});
        visited[src]=true;
        while(!q.empty())
        {
            int u=q.front().first;
            int parU=q.front().second;
            q.pop();
            list<int> neigh=l[u];
            for(int v:neigh)
            {
                if(!visited[v])
                {
                    q.push({v,u});
                    visited[v]=true;
                }
                else if(v!=parU)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle()
    { 
        vector<bool> visited(v,false);
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                if(isCycleDetectBFS(i,visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(4, 5);
    bool ans=g.isCycle();
    if(ans)
    {
        cout<<"Cycle is present\n";
    }
    else
    {
        cout<<"Cycle is not present\n";
    }
    return 0;
}