#include <iostream>
using namespace std;
int partition(int arr[],int s,int e)
{
    int pivot=arr[s],cnt=0;
    for (int i = s+1; i < e; i++)
    {
        if (arr[i]<=pivot)
        {
            cnt++;
        }
    }
    // place at right position
    int pivotindex=s+cnt,i=s,j=e;
    swap(arr[pivotindex],arr[s]); 
    while (i<pivotindex && j>pivotindex)
    {
        while (i<pivotindex)
        {
            i++;
        }
        while (j>pivotindex)
        {
            j--;
        }
        if (i<pivotindex && j>pivotindex)
        {
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotindex;
}
void Quicksort(int arr[],int s,int e)
{ 
    // base case
    if (s>=e)
    {
        return;
    }
    int p=partition(arr,s,e);
    // sort the first half 
    Quicksort(arr,s,p-1);
    // sort the remaining half 
    Quicksort(arr,p+1,e);    
}
int main() 
{
    int arr[]={2,1,0,3,4,9,5},n=sizeof(arr)/sizeof(arr[0]);
    Quicksort(arr,0,n-1);
    cout<<"Sorted array is as follows: "<<endl;
    for (auto i:arr)
    {
        cout<<i<<"\t";
    }
    return 0;
}