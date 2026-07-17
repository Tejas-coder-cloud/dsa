/*
Maximum Chocolates 
Time complexity:O(N*M*M)*9
Space complexity:O(N*M*M)+O(N)
*/
#include<bits/stdc++.h>
using namespace std;
int maximum_Chocolates(int r, int c,int i, int j1, int j2, vector<vector<int>>& grid,vector<vector<vector<int>>> &dp)
{
    if(j1<0 || j2<0 || j2>=c || j1>=c )
    {
        return -1e9;
    }
    if(i==r-1)
    {
        if(j1==j2)
        {
            return grid[i][j1];
        }
        else
        {
            return grid[i][j1]+grid[i][j2];
        }
    }
    if(dp[i][j1][j2]!=-1)
    {
        return dp[i][j1][j2];
    }
    int maxi=-1e9;
    for(int dj1=-1;dj1<=1;dj1++)
    {
        for(int dj2=-1;dj2<=1;dj2++)
        {
            int value=0;
            if(j1==j2)
            {
                value=grid[i][j1];
            }
            else
            {
                value=grid[i][j1]+grid[i][j2];
            }
            value+=maximum_Chocolates(r,c,i+1,j1+dj1,j2+dj2,grid,dp);
            maxi=max(maxi,value);
        }
    }
    return dp[i][j1][j2]=maxi;

}
int main()
{
    int r=3,c=3;
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    vector<vector<int>> grid=
    {
        {34,23,19},
        {10,35,67},
        {20,45,12}
    };
    int ans=maximum_Chocolates(r,c,0,0,c-1,grid,dp);
    cout<<"The maximum number of chocolates is: "<<ans<<endl;
    return 0;
}
/*
Maximum Chocolates (Tabulation)

Time Complexity: O(N * M * M * 9)
Space Complexity: O(N * M * M)

#include<bits/stdc++.h>
using namespace std;

int maximum_Chocolates(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(r,
        vector<vector<int>>(c, vector<int>(c, 0)));

        // Base Case
        for(int j1 = 0; j1 < c; j1++)
        {
            for(int j2 = 0; j2 < c; j2++)
            {
                if(j1 == j2)
                dp[r-1][j1][j2] = grid[r-1][j1];
                else
                dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
            }
        }
        
        // Fill the DP table from bottom to top
        for(int i = r - 2; i >= 0; i--)
        {
            for(int j1 = 0; j1 < c; j1++)
            {
                for(int j2 = 0; j2 < c; j2++)
                {
                    int maxi = -1e9;
                    
                    for(int dj1 = -1; dj1 <= 1; dj1++)
                    {
                        for(int dj2 = -1; dj2 <= 1; dj2++)
                        {
                            int value;
                            
                            if(j1 == j2)
                            value = grid[i][j1];
                            else
                            value = grid[i][j1] + grid[i][j2];
                            
                            if(j1 + dj1 >= 0 && j1 + dj1 < c &&
                            j2 + dj2 >= 0 && j2 + dj2 < c)
                            {
                                value += dp[i+1][j1+dj1][j2+dj2];
                            }
                            else
                            {
                                value += -1e9;
                            }
                            
                            maxi = max(maxi, value);
                        }
                }

                dp[i][j1][j2] = maxi;
            }
        }
    }
    
    return dp[0][0][c-1];
}

int main()
{
    int r = 3, c = 3;
    
    vector<vector<int>> grid =
    {
        {34,23,19},
        {10,35,67},
        {20,45,12}
    };
    
    cout << "The maximum number of chocolates is: "
    << maximum_Chocolates(r,c,grid);
    
    return 0;
}

Maximum Chocolates (Space Optimized)

Time Complexity: O(N * M * M * 9)
Space Complexity: O(M * M)


#include<bits/stdc++.h>
using namespace std;

int maximum_Chocolates(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<int>> front(c, vector<int>(c, 0));
    vector<vector<int>> curr(c, vector<int>(c, 0));

    // Base Case
    for(int j1 = 0; j1 < c; j1++)
    {
        for(int j2 = 0; j2 < c; j2++)
        {
            if(j1 == j2)
                front[j1][j2] = grid[r-1][j1];
            else
                front[j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }

    // Traverse from second last row to first row
    for(int i = r - 2; i >= 0; i--)
    {
        for(int j1 = 0; j1 < c; j1++)
        {
            for(int j2 = 0; j2 < c; j2++)
            {
                int maxi = -1e9;

                for(int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for(int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int value;

                        if(j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];

                        if(j1 + dj1 >= 0 && j1 + dj1 < c &&
                           j2 + dj2 >= 0 && j2 + dj2 < c)
                        {
                            value += front[j1+dj1][j2+dj2];
                        }
                        else
                        {
                            value += -1e9;
                        }

                        maxi = max(maxi, value);
                    }
                }

                curr[j1][j2] = maxi;
            }
        }

        front = curr;
    }

    return front[0][c-1];
}

int main()
{
    int r = 3, c = 3;

    vector<vector<int>> grid =
    {
        {34,23,19},
        {10,35,67},
        {20,45,12}
    };

    cout << "The maximum number of chocolates is: "
         << maximum_Chocolates(r,c,grid);

    return 0;
}
*/