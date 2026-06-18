/*
Course scheduling 
V = No of Vertices
E = No of Edges
Time complexity:O(V*E)
Space complexity:O(V)
 */
#include <bits/stdc++.h>
using namespace std;
bool isCycleDFS(int src, vector<bool> &visited, vector<bool> &recPath, vector<vector<int>> &prerequisites)
{
    visited[src] = true;
    recPath[src] = true;
    for (int i = 0; i < prerequisites.size(); i++)
    {
        int v = prerequisites[i][1];
        int u = prerequisites[i][0];
        if (u == src)
        {
            if (!visited[v])
            {
                if (isCycleDFS(v, visited, recPath, prerequisites))
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
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<bool> visited(numCourses, false);
    vector<bool> recPath(numCourses, false);
    for (int i = 0; i < numCourses; i++)
    {
        if (!visited[i])
        {
            if (isCycleDFS(i, visited, recPath, prerequisites))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int numCourses = 2;
    vector<vector<int>> prereq = {{1, 0}};
    bool ans=canFinish(numCourses,prereq);
    if(ans)
    {
        cout<<"Can complete all the courses\n";
    }
    else
    {
        cout<<"Cannot complete all the courses\n";
    }
    return 0;
}