#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            for(int j=i+1;j<n;j++)
            {
                if(j!=(i+1) && nums[j]==nums[j-1])
                {
                    continue;
                }
                int k=j+1,l=n-1;
                while(k<l)
                {
                    ll sum=1LL*nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==target)
                    {
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1])
                        {
                            k++;
                        }
                        while(k<l && nums[l]==nums[l+1])
                        {
                            l--;
                        }
                    }
                    else if(sum<target)
                    {
                        k++;
                    }
                    else
                    {
                        l--;
                    }
                }
            }
        }
        return ans;
    }
int main() 
{
    vector<int> v={1,0,-1,0,-2,2};
    int target=0;
    vector<vector<int>> ans=fourSum(v,target);
    cout<<"The quadruplets are as follows: "<<endl;
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}