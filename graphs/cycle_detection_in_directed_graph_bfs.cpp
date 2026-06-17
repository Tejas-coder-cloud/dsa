/*
Cycle detection in directed graph using BFS
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
    bool isCycleBFS()
    {
        vector<int> indegree(v, 0);
        for (int i = 0; i < v; i++)
        {
            for (int neigh : l[i])
            {
                indegree[neigh]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < v; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            for (int neigh : l[node])
            {
                indegree[neigh]--;
                if (indegree[neigh] == 0)
                {
                    q.push(neigh);
                }
            }
        }
        return count != v;
    }
};
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    bool ans = g.isCycleBFS();
    if (ans)
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "Cycle is not present" << endl;
    }
    return 0;
}