/*
Subset Sum Equal to K
Time Complexity: O(N * Target)
Space Complexity: O(N * Target) + O(N)
*/
#include<bits/stdc++.h>
using namespace std;
bool isTargetPresentInSubsequence(vector<int> & arr, vector<vector<int>>& dp,int target,int index)
{
    if(target==0)
    {
        return true;
    }
    if(index==0)
    {
        return arr[0]==target;
    }
    if(dp[index][target]!=-1)
    {
        return dp[index][target];
    }
    bool notTake=isTargetPresentInSubsequence(arr,dp,target,index-1);
    bool Take=false;
    if(arr[index]<=target)
    {
         Take=isTargetPresentInSubsequence(arr,dp,target-arr[index],index-1);
    }
    return dp[index][target]=Take|notTake;
}
int main()
{
    vector<int> arr={3,4,1,2};
    int target=10;
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    bool found=isTargetPresentInSubsequence(arr,dp,target,n-1);
    if(found)
    {
        cout<<"Target found "<<endl;
    }
    else
    {
        cout<<"Target not  found "<<endl;
    }
    return 0;
}
/*
Subset Sum Equal to K (Tabulation)

Time Complexity: O(N * Target)
Space Complexity: O(N * Target)

#include<bits/stdc++.h>
using namespace std;

bool isTargetPresentInSubsequence(vector<int> &arr, int target)
{
    int n = arr.size();
    
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
    
    // Base Case
    for(int i = 0; i < n; i++)
    dp[i][0] = true;
    
    if(arr[0] <= target)
    dp[0][arr[0]] = true;
    
    // Fill the DP table
    for(int index = 1; index < n; index++)
    {
        for(int tar = 1; tar <= target; tar++)
        {
            bool notTake = dp[index - 1][tar];
            
            bool take = false;
            if(arr[index] <= tar)
            take = dp[index - 1][tar - arr[index]];
            
            dp[index][tar] = take || notTake;
        }
    }
    
    return dp[n - 1][target];
}

int main()
{
    vector<int> arr = {3,4,1,2};
    int target = 7;
    
    if(isTargetPresentInSubsequence(arr, target))
    cout << "Target found";
    else
    cout << "Target not found";
    
    return 0;
}

Subset Sum Equal to K (Space Optimized)
Time Complexity: O(N * Target)
Space Complexity: O(Target)
#include<bits/stdc++.h>
using namespace std;

bool isTargetPresentInSubsequence(vector<int> &arr, int target)
{
    int n = arr.size();

    vector<bool> prev(target + 1, false);
    vector<bool> curr(target + 1, false);

    // Base Case
    prev[0] = true;

    if(arr[0] <= target)
        prev[arr[0]] = true;

    for(int index = 1; index < n; index++)
    {
        curr[0] = true;

        for(int tar = 1; tar <= target; tar++)
        {
            bool notTake = prev[tar];

            bool take = false;
            if(arr[index] <= tar)
                take = prev[tar - arr[index]];

            curr[tar] = take || notTake;
        }

        prev = curr;
    }

    return prev[target];
}

int main()
{
    vector<int> arr = {3,4,1,2};
    int target = 7;

    if(isTargetPresentInSubsequence(arr, target))
        cout << "Target found";
    else
        cout << "Target not found";

    return 0;
}
*/