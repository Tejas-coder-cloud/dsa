// Finding minimum in a rotated sorted array 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int start=0,end=nums.size()-1;
        while(start<end)
        {
             // already sorted
           if(nums[start] <= nums[end])
            return nums[start];
            int mid=start+(end-start)/2;
            if(nums[mid]>=nums[0])
            {
                start=mid+1;
            }
            else
            {
                end=mid;
            }
    
        }
        return nums[start];        
    }
};
int main()
{
    Solution sol;
    vector<int> arr={1,2,3,4};
    int ans=sol.findMin(arr);
    cout<<"Minimum in the array is: "<<ans<<endl;
    return 0;
}