/*
Frog jump
Time complexity:O(N)
Space complexity:O(1)
*/
#include <bits/stdc++.h>
using namespace std;
int frog_jump(vector<int> &arr)
{
    int n=arr.size();
    int prev2=0,prev1=0;
    for(int i=1;i<n;i++)
    {
        int fs=prev1+abs(arr[i]-arr[i-1]);
        int ss=INT_MAX;
        if(i>1 )
        {
            ss=prev2+abs(arr[i]-arr[i-2]);
        }
        int curr=min(ss,fs);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
int main()
{
    vector<int> arr={10,20,30,10};
    cout<<"Minimum cost is: "<<frog_jump(arr); 
    return 0;
}
/*
Memoized version of the code 
Time complexity:O(N)
Space complexity:O(N)
#include <bits/stdc++.h>
using namespace std;
int solve(int i , vector<int> &arr,vector<int> & dp)
{
    if(i==0) return 0;
    if(dp[i]!=-1) return dp[i];
    int fs=solve(i-1,arr,dp)+abs(arr[i]-arr[i-1]);
    int ss=INT_MAX;
    if(i>1)  ss=solve(i-2,arr,dp)+abs(arr[i]-arr[i-2]);
    dp[i]=min(fs,ss);
    return dp[i];
}
int frog_jump(vector<int> &arr)
{
    int n=arr.size();
    vector<int> dp(n,-1);
    return solve(n-1,arr,dp);
}
int main() 
{
    vector<int> arr={10,20,10};
    int ans=frog_jump(arr);
    cout<<"The minimum energy required is: "<<ans<<endl;
    return 0;
}
*/