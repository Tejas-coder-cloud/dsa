/*
Disjoint Set Union / Union Find
V = No of vertices
E = No of operations (unions/finds)
Time complexity: O(E * α(V)) ≈ O(E)  // α is the inverse Ackermann function, nearly O(1)
Space complexity: O(V)               // Only arrays of size V are needed
 */
#include <bits/stdc++.h>
using namespace std;
class DisjointSetUnion
{
public:
    int n;
    vector<int> par, rank;
    DisjointSetUnion(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
        {
            par.push_back(i);
            rank.push_back(0);
        }
    }
    int find(int x)
    {
        if (par[x] == x)
        {
            return x;
        }
        return par[x] = find(par[x]); // Path compression
    }
    void unionByRank(int a, int b)
    {
        int parA = find(a);
        int parB = find(b);
        if (parA == parB)
            return;
        if (rank[parA] == rank[parB])
        { // case 1
            par[parB] = parA;
            rank[parA]++;
        }
        else if (rank[parA] > rank[parB])
        { // case 2
            par[parB] = parA;
        }
        else
        { // case 3
            par[parA] = parB;
        }
    }
    void getInfo()
    {
        cout<<"The parent array is: ";
        for (int i = 0; i < n; i++)
        {
            cout << par[i] << " ";
        }
        cout << endl;
        cout<<"The rank array is as follows: ";
        for (int i = 0; i < n; i++)
        {
            cout << rank[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    DisjointSetUnion dsu(6);
    dsu.unionByRank(0, 2);
    cout << dsu.find(2) << endl;
    dsu.unionByRank(1, 3);
    dsu.unionByRank(2, 5);
    dsu.unionByRank(0, 3);
    cout << dsu.find(2) << endl;
    dsu.unionByRank(0, 4);
    dsu.getInfo();
    return 0;
}