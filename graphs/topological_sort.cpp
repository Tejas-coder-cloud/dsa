/*
Topological sort using DFS 
Topological sort is only applicable to directed acyclic graphs(DAG)
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
        this->v = size;
        l = new list<int>[size];
    }
    void addEdge(int u, int v)
    {
        l[u].push_back(v);
    }
    void dfs(int curr,vector<bool> & visited,stack<int> &s)
    {
        visited[curr]=true;
        for(int neigh:l[curr])
        {
            if(!visited[neigh])
            {
                dfs(neigh,visited,s);
            }
        }
        s.push(curr);
    }
    void topologicalSort()
    {
        vector<bool> visited(v,false);
        stack<int> s;
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                dfs(i,visited,s);
            }
        }
        cout<<"Topological sort is as follows: ";
        while(!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }
};
int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.topologicalSort();
    return 0;
}