/*
Count inversion
Time complexity:O(nlogn)
Space complexity:O(n)
*/
#include <bits/stdc++.h>
using namespace std;
int merge(vector<int> &arr, int s, int mid, int e)
{
    vector<int> temp;
    int i = s, j = mid + 1;
    int invCount = 0;
    while (i <= mid && j <= e)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
            invCount += (mid - i + 1);
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= e)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for (int idx = 0; idx < temp.size(); idx++)
    {
        arr[s + idx] = temp[idx];
    }
    return invCount;
}
int mergesort(vector<int> &arr, int s, int e)
{
    if (s < e)
    {
        int mid = s + (e - s) / 2;
        int leftInvCount = mergesort(arr, s, mid);
        int rightInvCount = mergesort(arr, mid + 1, e);
        int invCount = merge(arr, s, mid, e);
        int total = leftInvCount + rightInvCount + invCount;
        return total;
    }
    return 0;
}
int inversionCount(vector<int> &arr)
{
    int s = 0, e = arr.size() - 1;
    return mergesort(arr, s, e);
}
int main()
{
    vector<int> arr={3,1,4,0,-1};
    int invC=inversionCount(arr);
    cout<<"The inversion count of the arr is "<<invC<<endl;
    return 0;
}