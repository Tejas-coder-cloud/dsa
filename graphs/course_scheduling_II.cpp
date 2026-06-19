/*
Course scheduling II
V = No of Vertices
E = No of Edges
Time complexity:O(V*E)
Space complexity:O(V)
 */
#include <bits/stdc++.h>
using namespace std;
bool isCycleDFS(int src, vector<bool> &visited, vector<bool> &recPath, vector<vector<int>> &edges)
{
    visited[src] = true;
    recPath[src] = true;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][1];
        int v = edges[i][0];
        if (u == src)
        {
            if (!visited[v])
            {
                if (isCycleDFS(v, visited, recPath, edges))
                {
                    return true;
                }
            }
            else if (recPath[v])
            {
                return true;
            }
        }
    }
    recPath[src] = false;
    return false;
}
void topologicalSort(int src, stack<int> &s, vector<bool> &visited, vector<vector<int>> &edges)
{
    visited[src] = true;
    for (int i = 0; i < edges.size(); i++)
    {
        int v = edges[i][0];
        int u = edges[i][1];
        if (u == src)
        {
            if (!visited[v])
            {
                topologicalSort(v, s, visited, edges);
            }
        }
    }
    s.push(src);
}
vector<int> findOrder(int numCourses, vector<vector<int>> &edges)
{
    vector<bool> visited(numCourses, false);
    vector<bool> recPath(numCourses, false);
    vector<int> ans;
    for (int i = 0; i < numCourses; i++)
    {
        if (!visited[i])
        {
            if (isCycleDFS(i, visited, recPath, edges))
            {
                return ans;
            }
        }
    }
    stack<int> s;
    visited.assign(numCourses, false);
    for (int i = 0; i < numCourses; i++)
    {
        if (!visited[i])
        {
            topologicalSort(i, s, visited, edges);
        }
    }
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
int main()
{
    int numCourses = 2;
    vector<vector<int>> prereq = {{1, 0}};
    vector<int> ans = findOrder(numCourses, prereq);
    cout<<"The order is given as follows: ";
    for(auto it:ans )
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}