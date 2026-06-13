/*
Celebrity problem
Time complexity:O(n)
Space complexity:O(1)
 */
#include <bits/stdc++.h>
using namespace std;
int celebrity(vector<vector<int>> &mat)
{
    int n = mat.size();
    if (n == 0)
        return -1; // Protect against empty matrix
    // Phase 1: Find the candidate (O(1) Space Elimination)
    // Instead of a stack, we just keep track of a single candidate
    int candidate = 0;
    for (int i = 1; i < n; i++)
    {
        // If the candidate knows 'i', the candidate is fake.
        // 'i' becomes the new potential candidate.
        if (mat[candidate][i] == 1)
        {
            candidate = i;
        }
    }
    // Phase 2: Verify the candidate
    for (int i = 0; i < n; i++)
    {
        // We skip the diagonal (candidate checking themselves)
        if (i != candidate)
        {
            // If candidate knows someone OR someone doesn't know the candidate -> Fail
            if (mat[candidate][i] == 1 || mat[i][candidate] == 0)
            {
                return -1;
            }
        }
    }
    return candidate;
}
int main()
{
    vector<vector<int>> v={
        {1,0,0},
        {0,0,0},
        {1,0,1}
    };
    int ans=celebrity(v);
    cout<<"The celebrity is: "<<ans<<endl;
    return 0;
}