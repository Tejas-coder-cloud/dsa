/*
Print exactly 1 subsequence whose sum is equal to k
Time complexity:O(N*2^N)
Space complexity:O(N)
*/
#include <bits/stdc++.h>
using namespace std;
bool print1SubsequenceWhoseSumIsK(vector<int> &arr, vector<int> &ds, int index, int n, int s, int sum)
{
    if (index == n)
    {
        if (s == sum)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    ds.push_back(arr[index]);
    s += arr[index];
    if (print1SubsequenceWhoseSumIsK(arr, ds, index + 1, n, s, sum))
    {
        return true;
    }
    ds.pop_back();
    s -= arr[index];
    if (print1SubsequenceWhoseSumIsK(arr, ds, index + 1, n, s, sum))
    {
        return true;
    }
    return false;
}
int main()
{
    vector<int> arr = {1, 2, 1}, ds;
    int n = arr.size(), index = 0, s = 0, sum = 2;
    cout << "The subsequence whose sum is equal to " << sum << " is: " << endl;
    print1SubsequenceWhoseSumIsK(arr, ds, index, n, s, sum);
    return 0;
}