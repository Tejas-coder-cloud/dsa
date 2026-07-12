/*
Combination sum I
K = Average Length of a Combination
X = Number of Valid Combinations
T=target
Time complexity:O(K*2^T)
Space complexity:O(K*X)
*/
#include <bits/stdc++.h>
using namespace std;
void findCombinations(vector<int> &candidates, int target, int index, vector<vector<int>> &ans, vector<int> &ds)
{
    if (index == candidates.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }
    if (candidates[index] <= target)
    {
        ds.push_back(candidates[index]);
        findCombinations(candidates, target - candidates[index], index, ans, ds);
        ds.pop_back();
    }
    findCombinations(candidates, target, index + 1, ans, ds);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    findCombinations(candidates, target, 0, ans, ds);
    return ans;
}
int main()
{
    int target=8;
    vector<int> candidates={2,9,1,8,7};
    vector<vector<int>> ans=combinationSum(candidates,target);
    cout<<"The possible combinations are as follows:\n";
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}