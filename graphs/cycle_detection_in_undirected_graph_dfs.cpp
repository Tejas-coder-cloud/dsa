/*
Cycle detection in undirected graph using dfs 
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
    bool isCycleDetectDFS(int src,int par,vector<bool> & visited)
    {
        visited[src]=true;
        list<int> neigh=l[src];
        for(int v:neigh)
        {
            if(!visited[v])
            {
                if(isCycleDetectDFS(v,src,visited))
                {
                    return true;
                }
            }
            else if(v!=par)
            {
                return true;
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
                if(isCycleDetectDFS(i,-1,visited))
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