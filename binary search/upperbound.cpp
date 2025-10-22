#include <iostream>
#include <vector>
using namespace std;
int upperBound(const vector<int> &nums, int x)
{
    int start = 0;
    int end = nums.size();
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] > x)
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    return start;
}
int main()
{
    vector<int> a = {1, 2, 3, 4};
    int target = 2;
    int ans = upperBound(a, target);
    cout << ans;
    return 0;
}