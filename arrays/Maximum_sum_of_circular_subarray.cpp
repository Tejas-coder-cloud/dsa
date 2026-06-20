/*
Maximum sum of circular subarray
Time complexity:O(n)
Space complexity:O(1)
*/
#include <bits/stdc++.h>
using namespace std;
int maxSubarraySumCircular(vector<int> &nums)
{
    int total_sum = 0;
    int max_curr = 0;
    int max_global = nums[0];
    int min_curr = 0;
    int min_global = nums[0];

    for (int num : nums)
    {
        total_sum += num;
        max_curr = max(num, max_curr + num);
        max_global = max(max_global, max_curr);
        min_curr = min(num, min_curr + num);
        min_global = min(min_global, min_curr);
    }
    if (max_global < 0)
    {
        return max_global;
    }
    return max(max_global, total_sum - min_global);
}
int main()
{
    vector<int> test = {-2, -3, -3};
    int ans = maxSubarraySumCircular(test);
    cout << "The maximum sum of the circular subarray is given as: " << ans << endl;
    return 0;
}