#include <iostream>
#include<vector>
using namespace std;

int main() {
    int n,edges;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>edges;
    vector<vector<int>> adjMatrix(n,vector<int>(n,0));
    cout<<"Enter edges (format: u v for edge from u to v):"<<endl;
    for (int i = 0; i < edges; i++)
    { int u,v;
        cin>>u>>v;
        adjMatrix[u][v]=1;       
    }
    cout<<"Adjacency matrix"<<endl;
    for (int i = 0; i < n; i++)
    { for (int j = 0; j < n; j++)
    {
        cout<<adjMatrix[i][j]<<" ";
    }
        cout<<endl;
    }    
    return 0;
}