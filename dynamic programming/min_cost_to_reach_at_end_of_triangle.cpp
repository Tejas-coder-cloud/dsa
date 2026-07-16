/*
min_cost_to_reach_at_end_of_triangle
Time complexity:O(n*n)
Space complexity:O(n*n)+O(n)
*/
#include<bits/stdc++.h>
using namespace std;
int min_cost_to_reach_at_end_of_triangle(int i, int j, vector<vector<int>> & grid,vector<vector<int>> &dp,int n)
{
    if(i==n-1)
    {
        return grid[n-1][j];
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int d=grid[i][j]+min_cost_to_reach_at_end_of_triangle(i+1,j,grid,dp,n);
    int dg=grid[i][j]+min_cost_to_reach_at_end_of_triangle(i+1,j+1,grid,dp,n);
    return dp[i][j]= min(d,dg);
}
int main()
{
    vector<vector<int>> grid=
    {
        {1},
        {3,2},
        {8,7,5},
        {10,11,6,7}
    };
    int i=0,j=0,n=grid.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    int ans=min_cost_to_reach_at_end_of_triangle(i,j,grid,dp,n);
    cout<<"The minimum cost to reach at the end of the triangle: "<<ans<<endl;
    return 0;
}
/*
Minimum Path Sum in Triangle
Approach: Tabulation (Bottom-Up DP)
Time Complexity: O(n^2)
Space Complexity: O(n^2)
#include<bits/stdc++.h>
using namespace std;
int minimumPathSum(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));   
    // Base Case: Copy the last row
    for(int j = 0; j < n; j++)
    {
        dp[n-1][j] = triangle[n-1][j];
    }
    
    // Fill the DP table from bottom to top
    for(int i = n-2; i >= 0; i--)
    {
        for(int j = 0; j <= i; j++)
        {
            int down = triangle[i][j] + dp[i+1][j];
            int diagonal = triangle[i][j] + dp[i+1][j+1];
            
            dp[i][j] = min(down, diagonal);
        }
    }    
    return dp[0][0];
}
int main()
{
    vector<vector<int>> triangle =
    {
        {1},
        {3,2},
        {8,7,5},
        {10,11,6,7}
    };
    cout << "Minimum Path Sum = " << minimumPathSum(triangle);
    return 0;
}
/*
Minimum Path Sum in Triangle
Approach: Space Optimized DP
Time Complexity: O(n^2)
Space Complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
int minimumPathSum(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<int> front(n, 0);
    // Base Case: Last row
    for(int j = 0; j < n; j++)
    {
        front[j] = triangle[n-1][j];
    }
    // Traverse from second-last row upwards
    for(int i = n-2; i >= 0; i--)
    {
        vector<int> curr(n, 0);
        for(int j = 0; j <= i; j++)
        {
            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j+1];
            curr[j] = min(down, diagonal);
        }
        front = curr;
    }
    return front[0];
}
int main()
{
    vector<vector<int>> triangle =
    {
        {1},
        {3,2},
        {8,7,5},
        {10,11,6,7}
    };
    cout << "Minimum Path Sum = " << minimumPathSum(triangle);
    return 0;
}
*/