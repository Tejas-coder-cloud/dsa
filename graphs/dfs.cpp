#include <bits/stdc++.h>
using namespace std;
void dfs(unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj,vector<int> &component,int node)
{
    component.push_back(node);
    visited[node]=true;
    for(auto i:adj[node])
    {
        if(!visited[i])
        {
            dfs(visited,adj,component,i);
        }
    }
}
vector<vector<int>> printdfs(int n,int m,vector<vector<int>> edges)
{
    unordered_map<int,bool> visited;
    unordered_map<int,list<int>> adj;
    vector<vector<int>> ans;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            vector<int> component;
            dfs(visited,adj,component,i);
            ans.push_back(component);
        }
    }
    return ans;
}

int main() 
{
    int n=4,m=3;
    vector<vector<int>> edges=
    {
        {0,1},
        {1,2},
        {2,3}
    };  
    vector<vector<int>> ans=printdfs(n,m,edges);
    for(auto i:ans)
    {
        for(int node: i)
        {
        cout<<node<<",";
        }
        cout<<"|";
    }
    cout<<endl;
    return 0;
}