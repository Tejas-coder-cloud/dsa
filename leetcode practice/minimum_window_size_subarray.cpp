#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minlenwindow=INT_MAX;
        int low=0,high=0,currentsum=0;
        while(high<nums.size())
        {
            currentsum+=nums[high];
            high++;
            while(currentsum>=target)
            {
                int currentwindowsize=high-low;
                minlenwindow=min(minlenwindow,currentwindowsize);
                currentsum-=nums[low];
                low++;
            }
        }
        return minlenwindow==INT_MAX?0:minlenwindow;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector <int> arr={1,1,1,1,1};
    int target=7;
    int ans=sol.minSubArrayLen(target,arr);
    cout<<"Minimum size of the subarray is:"<<ans<<endl;
    return 0;
}