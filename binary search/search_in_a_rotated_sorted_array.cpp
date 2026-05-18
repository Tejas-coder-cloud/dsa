// search in a rotated sorted array 
#include<bits/stdc++.h>
using namespace std;
int binarysearch(const vector<int> & arr, int s,int e,int k)
{
    int start=s,end=e;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==k)
        {
            return mid;
        }
        else if(arr[mid]<k)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return -1;
}
int getpivot(const vector<int> & arr,int n)
{
    int start=0,end=n-1;
    while(start<end)
    {
        if(arr[start]<=arr[end])
        {
            return start;
        }
        int mid=start+(end-start)/2;
        if(arr[mid]>=arr[0])
        {
            start=mid+1;
        }
        else
        {
            end=mid;
        }
    }
    return start;
}
int search_in_sorted_array(const vector<int> & arr,int n,int k)
{
    int pivot=getpivot(arr,n);
    if(k>=arr[pivot] && k<=arr[n-1])
    {
        return binarysearch(arr,pivot,n-1,k);
    }
    else
    {
        return binarysearch(arr,0,pivot-1,k);
    }
}
int main()
{
    int k=1;
    vector<int> arr={7,9,1,2,3};
    int ans=search_in_sorted_array(arr,arr.size(),k);
    cout<<"The target element "<<k<<" is present at "<<ans<<" index"<<endl;
    return 0;
}