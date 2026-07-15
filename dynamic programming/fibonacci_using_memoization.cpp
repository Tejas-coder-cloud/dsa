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
/*
Fibonacci using dynamic programming(tabulation)
Time complexity:O(N)
Space complexity:O(1)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter a number to calculate its fibonacci: ";
    cin>>n;
    if (n <= 1)
    {
        cout << "The fibonacci of " << n << " is: " << n << endl;
    }
    else
    {
    int prev1=1,prev2=0;
    for(int i=2;i<=n;i++)
    {
        int curr=prev2+prev1;
        prev2=prev1;
        prev1=curr;
    }
    cout<<"The fibonacci of "<<n<<" is: "<<prev1<<endl;
}
*/