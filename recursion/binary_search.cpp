#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int start, int end, int k)
{
    if (start > end)
        return -1;
    int mid = start + (end - start) / 2;
    if (arr[mid] == k)
        return mid;
    else if (arr[mid] > k)
        return binarySearch(arr, start, mid - 1, k);
    else
        return binarySearch(arr, mid + 1, end, k);
}
int main()
{
    int arr[] = {2, 3, 4, 5, 6, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    cout << "Enter the element to be searched in the array: ";
    cin >> k;
    int result = binarySearch(arr, 0, n - 1, k);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}
