#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int s,int e)
{
    int pivot=arr[s],cnt=0;
    for (int  i=s+1;i<=e;i++)
    {
        if(arr[i]<pivot)
        {
            cnt++;
        }
    }
    int pivotindex=s+cnt;
    swap(arr[pivotindex],arr[s]);
    int i=s,j=e;
    while(i<pivotindex && j>pivotindex)
    {
        while(i<pivotindex && arr[i]<pivot)
        {
         i++;
        }
        while(j>pivotindex && arr[j]>pivot)
        {
         j--;
        }
        if(i<pivotindex && j>pivotindex)
        {
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotindex;
}
void Quicksort(int arr[],int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int p=partition(arr,s,e);
    Quicksort(arr,s,p-1);
    Quicksort(arr,p+1,e);
}
int main()
{
    int arr[]={2,1,0,9,8};
    int size=5;
    Quicksort(arr,0,size-1);
    for(int i: arr)
    {
        cout<<i<<" ";
    }
    return 0;
}
