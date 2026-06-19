/*
Topological Sort using Kahn's Algorithm
V = No of vertices 
E = No of edges
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
        this->v=v;
        l=new list<int> [v];
    }
    void addEdge(int u,int v)
    {
        l[u].push_back(v);
    }
    void topologicalSort()
    {
        vector<int> res;
        vector<int> indeg(v,0);
        for(int u=0;u<v;u++)
        {
            for(int neigh:l[u])
            {
                indeg[neigh]++;
            }
        }
        queue<int> q;
        for(int i=0;i<v;i++)
        {
            if(indeg[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            res.push_back(curr);
            for(int neigh:l[curr])
            {
                indeg[neigh]--;
                if(indeg[neigh]==0)
                {
                    q.push(neigh);
                }
            }
        }
        cout<<"Topological sort is given as: ";
        for(int val: res)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.topologicalSort();
    return 0;
}