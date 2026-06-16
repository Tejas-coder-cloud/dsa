/*
Sliding window maximum
Time complexity:O(n)
Space complexity:O(n)
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> dq;
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && nums[dq.back()] <= nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for (int i = k; i < n; i++)
    {
        ans.push_back(nums[dq.front()]);
        while (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && nums[dq.back()] <= nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(nums[dq.front()]);
    return ans;
}
int main()
{
    vector<int> test={3,-1,-2,4,5,6};
    int k=3;
    vector<int> ans=maxSlidingWindow(test,k);
    cout<<"The sliding window maximum array is: ";
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}