/*
First negative integer in window of size k
Time complexity:O(n)
Space complexity:O(k)
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> firstNegInt(vector<int> &arr, int k)
{
    // write code here
    deque<int> dq;
    vector<int> ans;
    int n = arr.size();
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }
    if (!dq.empty())
    {
        ans.push_back(arr[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }
    for (int i = k; i < n; i++)
    {
        if (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
        if (!dq.empty())
        {
            ans.push_back(arr[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}
int main()
{
    vector<int> test={-1,2,3,-2};
    int k=2;
    vector<int> ans=firstNegInt(test,k);
    cout<<"The first negative array is as follows: ";
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}