/*
Maximum product subarray
Time complexity:O(n)
Space complexity:O(1)
*/
#include <bits/stdc++.h>
using namespace std;
int maxProduct(vector<int> &nums)
{
    int globalMax = nums[0], currMax = nums[0], currMin = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        int currentNum = nums[i];
        int tempMax = currentNum * currMax;
        int tempMin = currentNum * currMin;
        currMin = min({currentNum, tempMax, tempMin});
        currMax = max({currentNum, tempMax, tempMin});
        globalMax = max(currMax, globalMax);
    }
    return globalMax;
}
int main()
{
    vector<int> a1 = {1, 2, 1, 0, 0, 0};
    int ans = maxProduct(a1);
    cout <<"The maximum product of subarray is: "<<ans<< endl;
    return 0;
}