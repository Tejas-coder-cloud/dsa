#include <bits/stdc++.h>
using namespace std;
int totalmaxprofit(vector<int> &arr)
{
    int total_profit = 0;
    if (arr.size() == 0)
    {
        return 0;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > arr[i - 1])
        {
            total_profit += arr[i] - arr[i - 1];
        }
    }
    return total_profit;
}
int main()
{
    vector<int> prices = {7, 5, 6, 1, 4};
    int ans = totalmaxprofit(prices);
    cout << " Maximum profit is as follows: " << ans;
    return 0;
}
/* Time complexity: O(n)
Space complexity: O(1)
*/