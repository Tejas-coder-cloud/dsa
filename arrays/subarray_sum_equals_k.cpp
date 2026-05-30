#include <bits/stdc++.h>
using namespace std;
int subarraySum(vector<int>& nums, int k) 
{
    unordered_map<int,int> mp;
    mp[0]=1;
    int n=nums.size(),prefixSum=0,total=0;
    for(int i=0;i<n;i++)
    {
        prefixSum+=nums[i];
        if(mp.count(prefixSum-k))
            {
                total+=mp[prefixSum-k];
                mp[prefixSum]++;
            }
        else
            {
                mp[prefixSum]++;
            }
        }
    return total;
}
int main() {
    vector<int> arr={4,2,6,7};
    int k=6;
    int ans=subarraySum(arr,k);
    cout<<"The total number of subarray with sum "<<k<<" is "<<ans<<endl;
    return 0;
}