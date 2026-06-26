/*
Min Cost to Connect All Points (Prim's Algorithm)
Time Complexity: O(V^2 log V)
Space Complexity: O(V^2)
*/
#include <bits/stdc++.h>
using namespace std;
int manDist(vector<vector<int>> &points, int p1, int p2)
{
    return abs(points[p1][0] - points[p2][0]) +
           abs(points[p1][1] - points[p2][1]);
}
int minCostConnectPoints(vector<vector<int>> &points)
{
    int n = points.size();
    // Min Heap -> (weight, node)
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;
    vector<bool> mstSet(n, false);
    int mstCost = 0;
    pq.push({0, 0});
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int wt = p.first;
        int node = p.second;
        if (mstSet[node])
            continue;
        mstSet[node] = true;
        mstCost += wt;
        for (int i = 0; i < n; i++)
        {
            if (!mstSet[i])
            {
                int edgeWt = manDist(points, node, i);
                pq.push({edgeWt, i});
            }
        }
    }
    return mstCost;
}
int main()
{
    int n;
    cout << "Enter number of points: ";
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    cout << "Enter the coordinates (x y):\n";
    for (int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1];
    }
    cout << "Minimum Cost to Connect All Points: "
         << minCostConnectPoints(points) << endl;
    return 0;
}