/*
Breadth First Search
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
    void bfs()
    {
        vector<bool> visited(v, false);
        cout << "BFS traversal is as follows: ";
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                queue<int> q;
                q.push(i);
                visited[i] = true;
                while (!q.empty())
                {
                    int src = q.front();
                    q.pop();
                    cout << src << " ";
                    for (int dest : l[src])
                    {
                        if (!visited[dest])
                        {
                            visited[dest] = true;
                            q.push(dest);
                        }
                    }
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.bfs();
    return 0;
}