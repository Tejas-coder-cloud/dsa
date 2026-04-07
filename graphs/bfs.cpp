#include<bits/stdc++.h>
using namespace std;
void bfs(unordered_map<int,bool> &visited,int node,unordered_map<int,list<int>> &adj,vector<int> &ans)
{
    queue<int> q;
    q.push(node);
    visited[node]=true;
    while(!q.empty())
    {
        int frontNode=q.front();
        q.pop();
        ans.push_back(frontNode);
        for(auto i:adj[frontNode])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i]=true;
            }
        }
    }
}
vector<int> printbfs(int node,vector<pair<int,int>> edges)
{
    vector<int> ans;
    unordered_map<int,bool> visited;
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++)
    {
        // forming the adjacency list
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<node;i++)
    {
        if(!visited[i])
        {
            bfs(visited,i,adj,ans);
        }
    }
    return ans;
}
int main()
{
    int n=4;
    vector<pair<int,int>> edges=
    {
        {1,2},
        {0,1},
        {2,3}
    };
    vector<int> ans=printbfs(n,edges);
    for(auto i:ans)
    {
        cout<<i<<",";
    }
    cout<<endl;
    return 0;
}