/*
Count the number of subsequence whose sum is equal to k
Time complexity:O(2^N)
Space complexity:O(N)
*/
#include <bits/stdc++.h>
using namespace std;
int countSubsequenceWhoseSumIsK(vector<int> &arr, int index, int n, int s, int sum)
{
    if (index == n)
    {
        if (s == sum)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    s += arr[index];
    int l= (countSubsequenceWhoseSumIsK(arr, index + 1, n, s, sum));
    s -= arr[index];
    int r= (countSubsequenceWhoseSumIsK(arr, index + 1, n, s, sum));
    return l+r;
}
int main()
{
    vector<int> arr = {1, 1,2};
    int n = arr.size(), index = 0, s = 0, sum = 2;
    int ans=countSubsequenceWhoseSumIsK(arr, index, n, s, sum);
    cout<<"The total number of subsequence of the array is: "<<ans<<endl;
    return 0;
}