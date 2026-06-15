/*
Depth First Search
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
    void dfsHelper(int src, vector<bool> &vis)
    {
        cout<<src<<" ";
        vis[src]=true;
        for(int n:l[src])
        {
            if(!vis[n])
            {
                dfsHelper(n,vis);
            }
        }
    }
    void dfs()
    {
        int src=0;
        vector<bool> vis(v,false);
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                dfsHelper(i,vis);
            }
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(4, 5);
    cout<<"dfs traversal is given as follows: ";
    g.dfs();
    return 0;
}