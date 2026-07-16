/*
Maximum Path Sum in a Matrix
Approach: Recursion + Memoization
Time Complexity: O(n × m)
Space Complexity: O(n × m) + O(n)
where,
n = Number of rows
m = Number of columns
O(n × m) -> DP table
O(n)     -> Recursive call stack
*/
#include<bits/stdc++.h>
using namespace std;
int maximum_path_sum(int i,int j,vector<vector<int>> & grid, vector<vector<int>> & dp,int n)
{
    if(j<0 || j>=n)
    {
        return -1e9;
    }
    if(i==0)
    {
        return grid[0][j];
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int left_diagonal=grid[i][j]+maximum_path_sum(i-1,j-1,grid,dp,n);
    int right_diagonal=grid[i][j]+maximum_path_sum(i-1,j+1,grid,dp,n);
    int up=grid[i][j]+maximum_path_sum(i-1,j,grid,dp,n);
    return dp[i][j]=max(up, max(left_diagonal,right_diagonal));
}
int main()
{
    vector<vector<int>> grid=
    {
        {3,100,2},
        {23,39,10},
        {34,76,21}
    };
    int n=grid.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    int ans=-1e9;
    for(int j=0;j<n;j++)
    {
        ans=max(ans,maximum_path_sum(n-1,j,grid,dp,n));
    }
    cout<<"The maximum path sum from any cell of the first row to the last row is: "<<ans;
    return 0;
}
/*
Maximum Path Sum in a Matrix
Approach: Tabulation (Bottom-Up DP)

Time Complexity: O(n * m)
Space Complexity: O(n * m)

Here,
n = Number of rows
m = Number of columns

#include<bits/stdc++.h>
using namespace std;

int maximumPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> dp(n, vector<int>(m, 0));
    
    // Base Case: First row
    for(int j = 0; j < m; j++)
    {
        dp[0][j] = grid[0][j];
    }
    
    // Fill the DP table
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int up = grid[i][j] + dp[i-1][j];
            
            int leftDiagonal = grid[i][j];
            if(j > 0)
            leftDiagonal += dp[i-1][j-1];
            else
            leftDiagonal += -1e9;
            
            int rightDiagonal = grid[i][j];
            if(j < m-1)
            rightDiagonal += dp[i-1][j+1];
            else
            rightDiagonal += -1e9;
            
            dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
        }
    }
    
    int maxi = -1e9;
    
    for(int j = 0; j < m; j++)
    {
        maxi = max(maxi, dp[n-1][j]);
    }
    
    return maxi;
}

int main()
{
    vector<vector<int>> grid =
    {
        {3,100,2},
        {23,39,10},
        {34,76,21}
    };
    
    cout << "Maximum Path Sum = " << maximumPathSum(grid);
    
    return 0;
}
/*
Maximum Path Sum in a Matrix
Approach: Space Optimized DP
Time Complexity: O(n * m)
Space Complexity: O(m)
Here,
n = Number of rows
m = Number of columns
#include<bits/stdc++.h>
using namespace std;
int maximumPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m, 0);
    // Base Case: First row
    for(int j = 0; j < m; j++)
    {
        prev[j] = grid[0][j];
    }
    // Traverse remaining rows
    for(int i = 1; i < n; i++)
    {
        vector<int> curr(m, 0);
        for(int j = 0; j < m; j++)
        {
            int up = grid[i][j] + prev[j];
            int leftDiagonal = grid[i][j];
            if(j > 0)
                leftDiagonal += prev[j-1];
            else
                leftDiagonal += -1e9;
            int rightDiagonal = grid[i][j];
            if(j < m-1)
                rightDiagonal += prev[j+1];
            else
                rightDiagonal += -1e9;
            curr[j] = max(up, max(leftDiagonal, rightDiagonal));
        }
        prev = curr;
    }
    int maxi = -1e9;
    for(int j = 0; j < m; j++)
    {
        maxi = max(maxi, prev[j]);
    }
    return maxi;
}
int main()
{
    vector<vector<int>> grid =
    {
        {3,100,2},
        {23,39,10},
        {34,76,21}
    };
    cout << "Maximum Path Sum = " << maximumPathSum(grid);
    return 0;
}
*/