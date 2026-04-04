/*
Time complexity: O(N+M) where N represent number of nodes and M represent number of edges
Space complexity: O(N)
*/
#include<bits/stdc++.h>
using namespace std;
bool isCyclicDFS(int node,int parent,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj)
{
    visited[node]=true;
    for(auto neighbour:adj[node])
    {
        if(!visited[neighbour])
        {
            bool ans=isCyclicDFS(neighbour,node,visited,adj);
            if(ans)
            {
                return true;
            }
        }
        else if(neighbour !=parent)
        {
            return true;
        }
    }
    return false;
}
string detectloop(vector<vector<int>> edges,int n,int m)
{
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            bool ans=isCyclicDFS(i,-1,visited,adj);
            if(ans==1)
            {
                return "Yes";
            }
        }
    }
    return "No";

}
int main()
{
    int n=3,m=2;
    vector<vector<int>> edges=
    {
        {0,1},
        {1,2}
    };
    string ans=detectloop(edges,n,m);
    cout<<"Cycle detected: "<<ans<<endl;
    return 0;
}