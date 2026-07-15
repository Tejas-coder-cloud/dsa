/*
Minimum path sum in grid 
Time complexity:O(n*m)
Space complexity:O(n*m)
*/
#include<bits/stdc++.h>
using namespace std;
int solve(int i,int j,vector<vector<int>> & grid,vector<vector<int>> & dp )
{
    if(i==0 && j==0)
    {
        return dp[0][0]=grid[0][0];
    }
    if(i<0 || j<0)
    {
        return 1e9;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int up=grid[i][j]+solve(i-1,j,grid,dp);
    int left=grid[i][j]+solve(i,j-1,grid,dp);
    return dp[i][j]=min(left,up);
}
int minCost(vector<vector<int>> & grid)
{
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return solve(n-1,m-1,grid ,dp);
}
int main()
{
    vector<vector<int>> grid=
    {
        {20,36,34},
        {29,75,12},
        {21,30,10}
    };
    int ans=minCost(grid);
    cout<<"The minimum cost to traverse from the top-left to right-bottom cell cell is: "<<ans<<endl;    
}
/*
Minimum Path Sum in Grid (Tabulation)
Time Complexity: O(n * m)
Space Complexity: O(n * m)
#include<bits/stdc++.h>
using namespace std;
int minCost(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
            }
            else
            {
                int up = 1e9;
                int left = 1e9;
                if(i > 0)
                up = grid[i][j] + dp[i-1][j];            
                if(j > 0)
                left = grid[i][j] + dp[i][j-1];            
                dp[i][j] = min(up, left);
            }
        }
    }    
    return dp[n-1][m-1];
}
int main()
{
    vector<vector<int>> grid =
    {
        {20,36,34},
        {29,75,12},
        {21,30,10}
    };
    int ans = minCost(grid);  
    cout << "The minimum cost to traverse from the top-left to right-bottom cell is: "
    << ans << endl;  
    return 0;
}
Minimum Path Sum in Grid (Space Optimized)
Time Complexity: O(n * m)
Space Complexity: O(m)
#include<bits/stdc++.h>
using namespace std;
int minCost(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m, 0);
    for(int i = 0; i < n; i++)
    {
        vector<int> curr(m, 0);
        for(int j = 0; j < m; j++)
        {
            if(i == 0 && j == 0)
            {
                curr[j] = grid[i][j];
            }
            else
            {
                int up = 1e9;
                int left = 1e9;
                if(i > 0)
                up = grid[i][j] + prev[j];       
                if(j > 0)
                left = grid[i][j] + curr[j-1];    
                curr[j] = min(up, left);
            }
        }   
        prev = curr;
    }   
    return prev[m-1];
}
int main()
{
    vector<vector<int>> grid =
    {
        {20,36,34},
        {29,75,12},
        {21,30,10}
    };
    int ans = minCost(grid);
    cout << "The minimum cost to traverse from the top-left to right-bottom cell is: "
    << ans << endl;   
    return 0;
}
*/