/*
Cycle detection in directed graph using DFS
V = No of Vertices
E = No of Edges
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
    Graph(int size)
    {
        this->v=size;
        l=new list<int>[size];
    }
    void addEdge(int u, int v)
    {
        l[u].push_back(v);        
    }
    bool isCycleDFS(int src,vector<bool> & visited, vector<bool> & recPath)
    {
        visited[src]=true;
        recPath[src]=true;
        for(int neigh:l[src])
        {
            if(!visited[neigh])
            {
                if(isCycleDFS(neigh,visited,recPath))
                {
                    return true;
                }
            }
            else if(recPath[neigh])
            {
                return true;
            }
        }
        recPath[src]=false;
        return false;
    }
    bool isCycle()
    {
        vector<bool> recPath(v,false);
        vector<bool> visited(v,false);
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                if(isCycleDFS(i,visited,recPath))
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
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    bool ans=g.isCycle();
    if(ans)
    {
        cout<<"Cycle is present"<<endl;
    }
    else
    {
        cout<<"Cycle is not present"<<endl;
    }
    return 0;
}