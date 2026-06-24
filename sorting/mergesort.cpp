#include<bits/stdc++.h>
using namespace std;
void merge(int *arr,int s,int e)
{
    int mid=s+(e-s)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    int *first=new int[len1];
    int *second=new int[len2];
    // copy the 2 parts
    int k=s;
    for (int i=0;i<len1;i++)
    {
        first[i]=arr[k++];
    }
    k=mid+1;
    for (int i=0;i<len2;i++)
    {
        second[i]=arr[k++];
    }
    int index1=0;
    int index2=0;
    k=s;
    while(index1<len1 && index2<len2)
    {
        if(first[index1]<second[index2])
        {
            arr[k++]=first[index1++];
        }
        else
        {
            arr[k++]=second[index2++];
        }
    }
    // The following loops were added in case if the array length isn't equal 
    while (index1<len1)
    {
        arr[k++]=first[index1++];
    }
     while (index2<len2)
    {
        arr[k++]=second[index2++];
    }
    // to avoid any memory leak 
    delete []first;
    delete []second;
}
void Mergesort(int *arr,int s,int e)
{ 
    int mid=s+(e-s)/2;
    // base case
    if (s>=e)
    {
        return;
    }
    //sorting the part before mid 
    Mergesort(arr,s,mid);
    // sorting the part after mid
    Mergesort(arr,mid+1,e);
    //Merge both parts
    merge(arr,s,e);
}
int main()
{
    int arr[5]={7,2,1,0,11};
    int n=sizeof(arr)/sizeof(arr[0]);
    Mergesort(arr,0,n-1);
    cout<<"Sorted array is as follows:"<<"\n";
    for (int i :arr)
    {
        cout<<i<<"\t";
    }
    return 0;
}