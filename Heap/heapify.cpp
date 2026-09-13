#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if(left <= n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if(right <= n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if(largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}
int main()
{
    int arr[100];
    int n = 5;
    arr[1] = 10;
    arr[2] = 30;
    arr[3] = 20;
    arr[4] = 50;
    arr[5] = 40;
    for(int i = n/2; i >= 1; i--)
    {
        heapify(arr, n, i);
    }
    cout << "Max Heap: ";
    for(int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}