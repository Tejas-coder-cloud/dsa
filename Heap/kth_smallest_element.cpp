/*
Time complexity:O(nlog(k))
Space complexity:O(k)
*/
#include <bits/stdc++.h>
using namespace std;
int kth_smallest(vector<int> &arr, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = k; i < arr.size(); i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
int main()
{
    vector<int> arr = {10, 14, 13};
    int k = 2;
    int ans = kth_smallest(arr, k);
    cout << "The " << k << "th smallest element is: " << ans << endl;
    return 0;
}