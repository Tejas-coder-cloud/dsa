/*
Fibonacci using dynamic programming(memoization)
Time complexity:O(N)
Space complexity:O(2N)
*/
#include<bits/stdc++.h>
using namespace std;
int fibonacci(int n,vector<int>& dp)
{
    if(n<=1)
    {
        return n;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    return dp[n]=fibonacci(n-1,dp)+fibonacci(n-2,dp);
}
int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<"The fibonacci of "<<n<<" is: "<<fibonacci(n,dp)<<endl;
}