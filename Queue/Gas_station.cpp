/*
Gas station
Time complexity:O(n)
Space complexity:O(1)
*/
#include <bits/stdc++.h>
using namespace std;
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int totalGas = 0, totalCost = 0;
    int start = 0, currGas = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        totalCost += cost[i];
        totalGas += gas[i];
        currGas += gas[i] - cost[i];
        if (currGas < 0)
        {
            start = i + 1;
            currGas = 0;
        }
    }
    return totalGas < totalCost ? -1 : start;
}
int main()
{
    vector<int> gas={2,3,4};
    vector<int> cost={5,6,7};
    int ans=canCompleteCircuit(gas,cost);
    if(ans==-1)
    {
        cout<<"The circular tour can't be completed \n";
    }
    else
    {
        cout<<"Circular tour can be completed if started at index: "<<ans<<endl;
    }
    return 0;
}