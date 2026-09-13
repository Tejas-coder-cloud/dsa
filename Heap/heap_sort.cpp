#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int size, int i)
{
    int largest = i;

    int left = 2 * i;
    int right = 2 * i + 1;

    if(left <= size && arr[left] > arr[largest])
    {
        largest = left;
    }

    if(right <= size && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, size, largest);
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

    // Step 1: Build Max Heap
    for(int i = n/2; i >= 1; i--)
    {
        heapify(arr, n, i);
    }

    // Heap Sort
    int size = n;

    while(size > 1)
    {
        // Step 1: Swap root with last leaf
        swap(arr[1], arr[size]);

        // Remove last element from heap
        size--;

        // Step 2: Put root in its correct position
        heapify(arr, size, 1);
    }

    cout << "Sorted array: ";

    for(int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}