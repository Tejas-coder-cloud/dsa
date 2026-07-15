/*
Count ways
Time complexity:O(m*n)
Space complexity:O(m*n)
*/
#include<bits/stdc++.h>
using namespace std;
int count_ways(int i, int j , vector<vector<int>> &dp)
{
    if(i==0 && j==0)
    {
        return 1;
    }
    if(i<0 ||j<0)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int left=count_ways(i-1,j,dp);
    int right=count_ways(i,j-1,dp);
    return dp[i][j]=left+right;
}
int main()
{
    vector<vector<int>> test=
    {
        {2,2},
        {1,1}
    };
    int n=test.size(),m=test[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    int ans=count_ways(n-1,m-1,dp);
    cout<<"The number of steps to reach destination is: "<<ans<<endl;
    return 0;
}
/*
Time Complexity: O(n * m)
Space Complexity: O(n * m)
#include<bits/stdc++.h>
using namespace std;
int countWays(int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            // Base Case
            if(i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                int up = 0;
                int left = 0;
                if(i > 0)
                up = dp[i - 1][j];
                if(j > 0)
                left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }    
    return dp[n - 1][m - 1];
}
int main()
{
    vector<vector<int>> test =
    {
        {2,2},
        {1,1}
    };
    int n = test.size();
    int m = test[0].size();
    cout << "The number of steps to reach destination is: "
    << countWays(n, m);  
    return 0;
}
*/