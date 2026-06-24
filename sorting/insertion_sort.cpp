#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
    
    int j=i-1;
    while(j>=0 && arr[j]>key)
    {
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
}
}

int main()
{
    int arr[]={2,4,5,1,3,0},n=sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,n);
    for(auto i:arr)
    {
        cout<<i;
    }
    return 0;
}