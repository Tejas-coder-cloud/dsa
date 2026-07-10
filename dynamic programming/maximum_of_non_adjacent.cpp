/*
Maximum sum of non adjacent elements 
Time complexity: O(n)
Space complexity: O(n)
*/
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> & arr, int n)
{
    if(n==0)
    {
        return arr[n];
    }
    if(n<0)
    {
        return 0;
    }
    int pick=arr[n]+solve(arr,n-2);
    int notpick=solve(arr,n-1);
    int ans=max(pick,notpick);
    return ans;
}
int maximum(vector<int> & arr)
{
    int n=arr.size();
    return solve(arr,n-1);
}
int main()
{
    vector<int> arr={3,1,4,0};
    int ans=maximum(arr);
    cout<<"The maximum sum of the non adjacent elements is: "<<ans<<endl;
    return 0;
}