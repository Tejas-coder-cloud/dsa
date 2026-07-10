/*
Maximum sum of non adjacent elements 
Time complexity: O(n)
Space complexity: O(n)
*/
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> & arr, int n, vector<int> & dp)
{
    if(n==0)
    {
        return arr[n];
    }
    if(n<0)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int pick=arr[n]+solve(arr,n-2,dp);
    int notpick=solve(arr,n-1,dp);
    return dp[n]=max(pick,notpick);
}
int maximum(vector<int> & arr)
{
    int n=arr.size();
    vector<int> dp(n,-1);
    return solve(arr,n-1,dp);
}
int main()
{
    vector<int> arr={3,1,4,0};
    int ans=maximum(arr);
    cout<<"The maximum sum of the non adjacent elements is: "<<ans<<endl;
    return 0;
}
/*
Space optimized version
Maximum sum of two non adjacent elements 
Time complexity:O(n)
Space complexity:O(1)
*/
/*
#include<bits/stdc++.h>
using namespace std;
int maximum(vector<int>&arr)
{
    int prev2=0,prev=arr[0],n=arr.size();
    for(int i=1;i<n;i++)
    {
        int take=arr[i];
        if(i>1)
        {
            take+=prev2;
        }
        int nottake=prev;
        int curri=max(take,nottake);
        prev2=prev;
        prev=curri;
    }
    return prev;
}
int main()
{
    vector<int> arr={2,1,4,9};
    int ans=maximum(arr);
    cout<<"The maximum sum of the non adjacent elements is "<<ans<<endl;
    return 0;
}
*/